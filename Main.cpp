#include "stdafx.h"
#include <iostream>
#include <string>
#include "ArchiveFile.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::iterator;

Zoo jZoo;
ArchiveFile archFile;
bool bExit = false;
stack<string> Cmd_stack;
Uint MsgNum = 0;

/**
 *  @brief     从消息队列中获取消息
 *             Get news from the message queue
 *  @param     z Zoo引用
 *             z reference of the Zoo object
 *  @return    无
 *             void
 */
void GetNews(Zoo& jz)
{
	string strMsg;
	while (jz.IsMsgEmpty() != true)
	{
		strMsg = jz.FrontMsg();
		jz.PopMsg();
		jz.LockMtxClock();
		cout << endl << "News: " << strMsg << endl;
		jz.UnlockMtxClock();
		if (strMsg.find(" is having baby...") != std::string::npos)
		{
			MsgNum++;
			gender gd = (gender)::IsHappened(GENDER_PROB);
			if (gd == MALE)
			{
				jz.LockMtxClock();
				cout << "It's a boy!" << endl;
				jz.UnlockMtxClock();
			}
			else if (gd == FEMALE)
			{
				jz.LockMtxClock();
				cout << "It's a girl!" << endl;
				jz.UnlockMtxClock();
			}
			Asian_Elephant ase = jz.PopFetAse();
			ase.SetGender(gd);
			Uint birthTicks = jz.GetTicks();
			ase.SetBirthTicks(birthTicks);
			Uint id = jz.IncAnimalNum();
			ase.SetId(id);
			jz.LockMtxClock();
			jz.PushAse(ase);
			jz.UnlockMtxClock();
            if (Cmd_stack.empty() == true || (Cmd_stack.empty()!=true && Cmd_stack.top() != "News"))
	        {
				Cmd_stack.push("News");
	        }
		}
	}
	
}

/**
 *  @brief     用于获取消息的线程运行函数
 *             Get news thread function
 *  @param     z Zoo引用
 *             z reference of the zoo object
 *  @return    无
 *             void
 */
void RunGetNews(Zoo& jz)
{
	while (!bExit)
	{
		GetNews(jz);
		Sleep(200);
	}

}

/**
 *  @brief     在控制台上打印动物园状态信息
 *             Print the zoo information on the console
 *  @param     无
 *             void
 *  @return    无
 *             void
 */
void ShowStatus()
{
	cout << endl << "Zoo Status:" << endl;
	cout << "    Manager Name: " + jZoo.managerName << endl;
	cout << "    Species Number: " + to_string(jZoo.speciesNum) << endl;
	cout << "    Animal Number: " + to_string(jZoo.animalNum) << endl;
	cout << "    Funds: " + to_string(jZoo.funds) << endl;
	cout << "    Operating Ticks: " + to_string(jZoo.opTicks) << endl;
	cout << "Asian Elephant Status:" << endl;
	for (vector<Asian_Elephant>::iterator it = jZoo.asEle_vec.begin(); it != jZoo.asEle_vec.end(); it++)
	{
        cout << "    Name: " + it->name << endl;
        cout << "    ID: " + to_string(it->id) << endl;
        cout << "    Birth Place: " + it->birthPlace << endl;
		string strGd = it->gd == MALE ? "Male" : (it->gd == FEMALE ? "Female" : "Unknow");
		cout << "    Gender: " + strGd << endl;
		cout << "    Age Ticks: " + to_string(it->ageTicks) << endl;
		cout << "    Birth Ticks: " + to_string(it->birthTicks) << endl;
		cout << "    Hungry Ticks: " + to_string(it->hungryTicks) << endl;
        cout << "    Mate Ticks: " + to_string(it->mateTicks) << endl;
        cout << "    Pregnant Ticks: " + to_string(it->pregTicks) << endl;
        cout << "    Pregnant: " + to_string(it->preg) << endl;
		cout << "    Father Name: " + it->father << endl;
        cout << "    Mother Name: " + it->mother << endl;
		cout << "    Height: " + to_string(it->height) << endl;
		cout << "    Length: " + to_string(it->length) << endl;
        cout << "    Weight: " + to_string(it->weight) << endl;
		cout << "    Width: " + to_string(it->width) << endl;
        cout << "    Price: " + to_string(it->price) << endl;
		cout << "    Live: " + to_string(it->live) << endl << endl;
	
	}
	cout<< "Asian Elephant Fetus Number: "+ to_string(jZoo.aseFetus_que.size())<<endl;
}

/**
 *  @brief     解析玩家输入的命令
 *             Parse the commands the player inputs
 *  @param     z Zoo引用
 *             z reference of the zoo object
 *  @return    bool 解析成功true，失败false
 *             bool true if success, false if fail
 */
bool ParseCmd(Zoo& jz)
{
	while (!Cmd_stack.empty())
	{
		string str = Cmd_stack.top();
		Cmd_stack.pop();
		if (str == "Buy Asian elephant")
		{
			if (!jz.DecMoney(BABY_ASE_PRICE))
			{
				jz.LockMtxClock();
				cout << "I'm afraid you don't have enough money!" << endl;
				jz.UnlockMtxClock();
				return false;
			}
			jz.LockMtxClock();
			cout << "What gender do you want?" << endl;
			string strGd;
			gender gd;
			getline(cin, strGd);
			gd = strGd == "Male" ? MALE : FEMALE;
			if (gd == MALE)
				cout << "What name do you want to give him?" << endl;
			else if (gd == FEMALE)
				cout << "What name do you want to give her?" << endl;
			string strName;
			getline(cin, strName);
			Asian_Elephant ase(jz.IncAnimalNum(), strName, jz.GetTicks(), "Unknow", "Unknow", gd);
			jz.PushAse(ase);
			jz.UpdateSpeciesNum();
			cout << "You have bought an Asian elephant, cost $50000!" << endl;
			jz.UnlockMtxClock();

		}
		else if (str == "Sell Asian elephant")
		{
			string strName;
			jz.LockMtxClock();
			cout << "Please input the name of the elephant you want to sell!" << endl;
			getline(cin, strName);
			Asian_Elephant ase = jz.RemoveAse(strName);
			if (ase.GetBirthTicks() != 0)
			{
				Uint asePrive = jz.GetAsePrice(ase);
				jz.IncMoney(asePrive);
				cout << "Goodbye " + strName + "!" << endl;
			}
			else
			{
				cout << strName + " is not our child!" << endl;
			}
			jz.UnlockMtxClock();
		}
		else if (str == "Mate Asian elephant")
		{
			jz.LockMtxClock();
			string strMaleName, strFemaleName;
			cout << "Please input the name of the male elephant!" << endl;
			getline(cin, strMaleName);
			cout << "Please input the name of the female elephant!" << endl;
			getline(cin, strFemaleName);
			mateMsg mateMsg = jz.MateAsianElephant(strMaleName, strFemaleName);
			switch (mateMsg)
			{
			case PREGNANT:
			{
				cout << "Congratulations! " + strFemaleName + " is pregnant!" << endl;
				Asian_Elephant fetAse(0, "Unknow", 0, strMaleName, strFemaleName, UNKNOWGD);
				jz.PushFetAse(fetAse);
				break;
			}
			case NOTPREGNANT:
				cout << strFemaleName + " and " + strMaleName + " had a good time ^_^" << endl;
				break;
			case MALE_UNDERMATEAGE:
				cout << strMaleName + " is under mating age!" << endl;
				break;
			case FEMALE_UNDERMATEAGE:
				cout << strFemaleName + " is under mating age!" << endl;
				break;
			case MALE_NOTREADY:
				cout << strMaleName + " is not ready!" << endl;
				break;
			case FEMALE_NOTREADY:
				cout << strFemaleName + " is not ready!" << endl;
				break;
			case SEX_WRONG:
				cout << "Wrong sex!" << endl;
				break;
			case INBREED:
				cout << "Inbreeding!" << endl;
				break;
			case MISSING_MALE:
				cout << strMaleName + " is not our child!" << endl;
				break;
			case MISSING_FEMALE:
				cout << strFemaleName + " is not our child!" << endl;
				break;
			}
			jz.UnlockMtxClock();

		}
		else if (str == "Feed Asian elephant")
		{
			jz.LockMtxClock();
			string strName;
			cout << "Please input the name of the elephant you want to feed!" << endl;
			getline(cin, strName);
			Asian_Elephant ase = jz.FindAse(strName);
			if (ase.CheckLife() == false)
			{
				cout << "I'm afraid we don't have this child!" << endl;
			}
			else
			{
				if (jz.DecMoney(ASE_FOOD_COST))
				{
					jz.Feed(ase);
					cout << strName + " is full and happy^_^" << endl;
				}
				else
				{
					cout << "You don't have enough money!" << endl;
				}
			}
			jz.UnlockMtxClock();
		}
		else if (str == "Status")
		{
			jz.LockMtxClock();
			ShowStatus();
			jz.UnlockMtxClock();
		}
		else if (str == "Save")
		{
			jz.LockMtxClock();
			string strFile;
			cout << "Please input the file name:" << endl;
			getline(cin, strFile);
			archFile.SetFileName(strFile);
			if (archFile.Save(jz))
				cout << "Save successful!" << endl;
			else
				cout << "Save failed!" << endl;
			jz.UnlockMtxClock();
		}
		else if (str == "Quit")
		{
			return true;
		}
		else if (str == "News")
		{
		    jz.LockMtxClock();
		    while (MsgNum)
		    {
				MsgNum--;
                string strName, strFatherName, strMotherName;
				gender gd;
				Asian_Elephant ase = jz.FindAse("Unknow");
				while (ase.CheckLife() == true)
				{
					strFatherName = ase.GetFatherName();
					strMotherName = ase.GetMotherName();
					gd = ase.GetGender();
					if (gd == MALE)
					{
                        cout << "What name do you want to give " + strFatherName + " and " + strMotherName + "'s new boy?" << endl;
					}
					else if (gd == FEMALE)
					{
						cout << "What name do you want to give " + strFatherName + " and " + strMotherName + "'s new girl?" << endl;
					}
                    getline(cin, strName);    
				    ase.Naming(strName);
					cout << strName + ": I like it ^_^" << endl;
				}  
		    }
		    jz.UnlockMtxClock();
		}
		else if (str == "Help")
		{
			jz.LockMtxClock();
			cout << "Command description:" << endl;
			cout << "<Buy Asian elephant>      Buy an Asian elephant" << endl;
			cout << "<Sell Asian elephant>     Sell an Asian elephant" << endl;
			cout << "<Mate Asian elephant>     Mate 2 Asian elephants" << endl;
			cout << "<Feed Asian elephant>     Feed an Asian elephant" << endl;
			cout << "<Status>                  Show the zoo status" << endl;
			cout << "<Save>                    Save the game" << endl;
			cout << "<Quit>                    Quit the game" << endl;
			cout << "<Help>                    Show the commands" << endl;
			jz.UnlockMtxClock();
		}
		else
		{
			jz.LockMtxClock();
			cout << "Wrong command, please input again!" << endl;
			jz.UnlockMtxClock();
		}
	}
	
	return false;
}

/**
 *  @brief     读玩家命令循环
 *             Read commands loop
 *  @param     z Zoo引用
 *             z reference of the zoo object
 *  @return    无
 *             void
 */
void Console_Loop(Zoo& jz)
{
	string strCmd;
	std::thread thd(RunGetNews, std::ref(jz));
	thd.detach();
	while (!bExit)
	{
		std::getline(cin, strCmd);
		Cmd_stack.push(strCmd);
		bExit = ParseCmd(jz);
	}

}

/**
 *  @brief     主函数
 *             Main flow
 *  @param     无
 *             void
 *  @return    int
 */
int main()
{
	while(true)
	{
		cout << "*******************************" << endl;
	    cout << "*****Welcome to the J Zoo!*****" << endl;
	    cout << "*******************************" << endl;
	    cout << "Do you want to start a new game or load one?" << endl;
	    cout << "1: Start a new game   2: Load a game   3: Quit" << endl;
	    cout << "Please select command number..." << endl;

		bExit = false;
		string strInit, strFile, strName;
		getline(cin, strInit);
		if (strInit == "1")
		{
			cout << "Starting a new game!" << endl;
			cout << "Please input your name:" << endl;
			getline(cin, strName);
			cout << "J:Hello " + strName + ", I'm J, welcome to my zoo! Eh...Actually, it's not a real zoo yet." << endl;
			cout << "  I just bought this land as a zoo but I don't have time to take care of it." << endl;
			cout << "  That's why I need a young man like you to help me run it." << endl;
			cout << "  Here is $1000000 for the initial funding! Make my zoo wonderful!" << endl;
			cout << "  See you! Good luck!" << endl;
			cout << endl << "Please enter the commands!" << endl << "Enter 'Help' for commands information." << endl;
			jZoo.HireManager(strName);
			Console_Loop(jZoo);
		}
		else if (strInit == "2")
		{
			cout << "Loading a game, please wait..." << endl;
			cout << "Please input the file name:" << endl;
			getline(cin, strFile);
			archFile.SetFileName(strFile);
			if (archFile.Load(jZoo))
			{
				cout << "Loading successful!" << endl;
				Console_Loop(jZoo);
			}
		}
		else if (strInit == "3")
		{
			cout << "Quit game!" << endl;
			return 0;
		}
	}

	return 0;
}
