#include "stdafx.h"
#include <iostream>
#include <string>
#include "ArchiveFile.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

Zoo jZoo;
ArchiveFile archFile;
bool bExit = false;
std::mutex mtx;


void GetNews(Zoo& jz)
{
	string strMsg;
	mtx.lock();
	while (jz.IsMsgEmpty() != true)
	{
		strMsg = jz.PopMsg();
                cout << endl << "News: " << strMsg << endl;
		if (strMsg.find(" is having baby...")!=std::string::npos)
		{
			gender gd = (gender)::IsHappened(GENDER_PROB);
			if (gd == MALE)
			{
				cout << "It's a boy! What name do you want to give him?" << endl;
			}
			else if (gd == FEMALE)
			{
				cout << "It's a girl! What name do you want to give her?" << endl;
			}
			string strName;
			getline(cin, strName);
			Asian_Elephant ase = jz.PopFetAse();
			ase.Naming(strName);
			Uint birthTicks = jz.GetTicks();
			ase.SetBirthTicks(birthTicks);
			Uint id = jz.IncAnimalNum();
			ase.SetId(id);
			jz.PushAse(ase);
		}
	}
	mtx.unlock();
}

void RunGetNews(Zoo& jz)
{
	while (!bExit)
	{
		GetNews(jz);
		Sleep(200);
	}

}

bool ParseCmd(const string& str, Zoo& jz)
{
	if (str == "Buy an Asian elephant")
	{
		if (!jz.DecMoney(BABY_ASE_PRICE))
		{
			mtx.lock();
			cout << "I'm afraid you don't have enough money!" << endl;
			mtx.unlock();
			return false;
		}
                mtx.lock();
		cout << "What gender do you want?" << endl;
		string strGd;
		gender gd;
		getline(cin, strGd);
		gd = strGd == "Male" ? MALE : FEMALE;
		if(gd == MALE)
		    cout << "What name do you want to give him?" << endl;
		else if(gd == FEMALE)
			cout << "What name do you want to give her?" << endl;
		string strName;
		getline(cin, strName);
		Asian_Elephant ase(jz.IncAnimalNum(), strName, jz.GetTicks(), "Unknow", "Unknow", gd);
		jz.PushAse(ase);
		jz.UpdateSpeciesNum();
		cout << "You have bought an Asian elephant, cost $50000!" << endl;
		mtx.unlock();

	}
	else if (str == "Mate Asian elephant")
	{
		mtx.lock();
		string strMaleName,strFemaleName;
		cout << "Please input the name of the male elephant!" << endl;
		getline(cin, strMaleName);
		cout << "Please input the name of the female elephant!" << endl;
		getline(cin, strFemaleName);
		mateMsg mateMsg = jz.MateAsianElephant (strMaleName, strFemaleName);
		switch(mateMsg)
		{
		case PREGNANT:
		{
			cout << "Congratulations! "+ strFemaleName + " is pregnant!" << endl;
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
		mtx.unlock();

	}
	else if (str == "Feed Asian elephant")
	{
		mtx.lock();
		string strName;
		cout << "Please input the name of the elephant you want to feed!" << endl;
		getline(cin, strName);
		Asian_Elephant* pAse = jz.Find(strName);
		if (jz.DecMoney(ASE_FOOD_COST))
		{
            jz.Feed(*pAse);
			cout << strName + " is full and happy^_^" << endl;
		}
		else
		{
			cout << "You don't have enough money!" << endl;
		}
                mtx.unlock();
	}
	else if (str == "Show me the status")
	{
                mtx.lock();
		cout << "Please enter the command or call Help!" << endl;
		mtx.unlock();
	}
	else if (str == "Save game")
	{
		mtx.lock();
		string strFile;
		cout << "Please input the file name:" << endl;
		getline(cin, strFile);
		archFile.SetFileName(strFile);
		if (archFile.Save(jz))
			cout << "Save successful!" << endl;
		else
			cout << "Save failed!" << endl;
		mtx.unlock();
	}
	else if (str == "Quit game")
	{
		return true;
	}
	else if (str == "News")
	{
	    GetNews(jz);
    }
	else if (str == "Help")
	{
		mtx.lock();
		cout << "Command description:" << endl;
		cout << "<Buy an Asian elephant>   Buy an Asian elephant" << endl;
		cout << "<Mate Asian elephant>     Mate 2 Asian elephants" << endl;
		cout << "<Feed Asian elephant>     Feed an Asian elephant" << endl;
		cout << "<Show me the status>      Show the zoo status" << endl;
		cout << "<Save game>               Save the game" << endl;
		cout << "<Quit game>               Quit the game" << endl;
		mtx.unlock();
	}
	else
	{
		mtx.lock();
		cout << "Wrong command, please input again!" << endl;
		mtx.unlock();
	}

	return false;
}

void Console_Loop(Zoo& jz)
{
	string strCmd;
	std::thread thd(RunGetNews, std::ref(jz));
	thd.detach();
	while (!bExit)
	{
		std::getline(cin, strCmd);
		bExit = ParseCmd(strCmd, jz);
	}

}

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
