#include "stdafx.h"
#include <iostream>
#include <string>
#include "Zoo.h"
#include "ArchiveFile.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

Zoo jZoo;
ArchiveFile archFile;

bool ParseCmd(const string& str, Zoo& jz)
{
	if (str == "Buy an Asian elephant")
	{
		string strTmp;
		gender gd;
		if (!jz.DecMoney(BABY_ASE_PRICE))
		{
			cout << "I'm afraid you don't have enough money!" << endl;
			return false;
		}

		cout << "What gender do you want?" << endl;
		getline(cin, strTmp);
		gd = strTmp == "Male" ? MALE : FEMALE;
		if(gd == MALE)
		    cout << "What name do you want to give him?" << endl;
		else if(gd == FEMALE)
			cout << "What name do you want to give her?" << endl;
		getline(cin, strTmp);
		Asian_Elephant ase(jz.IncAnimalNum(), strTmp, jz.GetTicks(), gd);
		jz.PushAse(ase);
		jz.UpdateSpeciesNum();
		cout << "You have bought an Asian elephant, cost $50000!" << endl;
		cout << "Please enter the command or call Help!" << endl;
	}
	else if (str == "Mate Asian elephant")
	{
		string strMaleName,strFemaleName;

		cout << "Please input the name of the male elephant!" << endl;
		getline(cin, strMaleName);
		cout << "Please input the name of the female elephant!" << endl;
		getline(cin, strFemaleName);
		bool bPreg = jz.MateAsianElephant (strMaleName, strFemaleName);
	}
	else if (str == "Show me the status")
	{

		cout << "Please enter the command or call Help!" << endl;
	}
	else if (str == "Save game")
	{
		string strFile;
		cout << "Please input the file name:" << endl;
		getline(cin, strFile);
		archFile.SetFileName(strFile);
		if (archFile.Save(jz))
			cout << "Save successful!" << endl;
		else
			cout << "Save failed!" << endl;
	}
	else if (str == "Quit game")
	{
		return true;
	}
	else if (str == "Help")
	{
		cout << "Command description:" << endl;
		cout << "<Buy an Asian elephant> Buy an Asian elephant" << endl;
		cout << "<Show me the status>    Show the zoo status" << endl;
		cout << "<Save game>             Save the game" << endl;
		cout << "<Quit game>             Quit the game" << endl;
	}
	else
	{
		cout << "Wrong command, please input again!" << endl;
	}
	return false;
}

void Console_Loop(Zoo& jz)
{
	bool bExit = false;
	string strCmd;
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