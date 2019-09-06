#include "ArchiveFile.h"



ArchiveFile::ArchiveFile()
{

}

ArchiveFile::ArchiveFile(const string& strFile):fileName(strFile)
{

}


ArchiveFile::~ArchiveFile()
{

}

void ArchiveFile::SetFileName(const string & strFile)
{
	fileName = strFile;
}

bool ArchiveFile::Load(Zoo& z) 
{
	if (fileName == "")
		return true;
	infile.open(fileName, std::ios::in);
	if (!infile)
		return false;
	string strKey, strValue;

	while (infile >> strKey >> strValue)
	{
		if (strKey == "Manager_Name")
		{
			z.managerName = strValue;
		}
		else if (strKey == "Species_Num")
		{
			Uint num;
			stringstream ss;
			ss<< strValue;
			ss >> num;
			z.speciesNum = num;
		}
		else if (strKey == "Funds")
		{
			ULLong fund;
			stringstream ss;
			ss << strValue;
			ss >> fund;
			z.funds = fund;
		}
		else if (strKey == "Operating_Ticks")
		{
			ULLong op;
			stringstream ss;
			ss << strValue;
			ss >> op;
			z.opTicks = op;
		}
		else if (strKey == "Current_Time")
		{
			z.currentTime = strValue;
		}
		else if (strKey == "<Asian_Elephant>")
		{
			Uint unQty;
			vector<Uint> unIDVec;
			vector<string> sNameVec;
			vector<string> sBirthPlaceVec;
			vector<Uint> unTicksVec;
			vector<Uint> unBirthTickVec;
			vector<Uint> unPriceVec;
			vector<Uint> unWgtVec;
			vector<Uint> unHgtVec;
			vector<Uint> unWidVec;
			vector<Uint> unLenVec;
			vector <gender> gendVec;

			while (infile >> strKey >> strValue)
			{
				if (strKey == "Quantity")
				{
					stringstream ss;
					ss << strValue;
					ss >> unQty;
				}
		        else if (strKey == "ID")
				{
					vector<string> sIDVec = SplitString(strValue, ",");
					unIDVec = CvtStoUnVec(sIDVec);
				}
				else if (strKey == "Name")
				{
					sNameVec = SplitString(strValue,",");
					
				}
				else if (strKey == "Birthplace")
				{
					sBirthPlaceVec = SplitString(strValue, ",");

				}
				else if (strKey == "Ticks")
				{
					vector<string> sTicksVec = SplitString(strValue, ",");
					unTicksVec = CvtStoUnVec(sTicksVec);
				}
				else if (strKey == "BirthTicks")
				{
					vector<string> sBirthTickVec = SplitString(strValue, ",");
					unBirthTickVec = CvtStoUnVec(sBirthTickVec);
				}
				else if (strKey == "Price")
				{
					vector<string> sPriceVec = SplitString(strValue, ",");
					unPriceVec = CvtStoUnVec(sPriceVec);
				}
				else if (strKey == "Weight")
				{
					vector<string> sWgtVec = SplitString(strValue, ",");
					unWgtVec = CvtStoUnVec(sWgtVec);
				}
				else if (strKey == "Height")
				{
					vector<string> sHgtVec = SplitString(strValue, ",");
					unHgtVec = CvtStoUnVec(sHgtVec);
				}
				else if (strKey == "Width")
				{
					vector<string> sWidVec = SplitString(strValue, ",");
					unWidVec = CvtStoUnVec(sWidVec);
				}
				else if (strKey == "Length")
				{
					vector<string> sLenVec = SplitString(strValue, ",");
					unLenVec = CvtStoUnVec(sLenVec);
				}
				else if (strKey == "Gender")
				{
					gender gend;
					vector<string> sGendVec = SplitString(strValue, ",");
					for (vector<string>::iterator it = sGendVec.begin(); it != sGendVec.end(); it++)
					{
						if (*it == "Male")
							gend = MALE;
						else
							gend = FEMALE;
						gendVec.push_back(gend);
					}
				}
			}
			z.asEle_vec.clear();
			for (int i = 0; i < unQty; i++)
			{
				Asian_Elephant asEle(unIDVec[i], sNameVec[i], sBirthPlaceVec[i], unTicksVec[i], unBirthTickVec[i], unPriceVec[i], unWgtVec[i], unHgtVec[i], unWidVec[i], unLenVec[i], gendVec[i]);
				z.asEle_vec.push_back(asEle);
			}
		}
	}
	return true;
}

bool ArchiveFile::Save(const Zoo& z)
{
	if (fileName == "")
		return false;
	outfile.open(fileName, std::ios::out);
	if (!outfile)
		return false;
	int i = 0;
	Uint nQty = z.asEle_vec.size();
	outfile << "<Zoo> NULL" << endl;
	outfile << "Manager_Name " << z.managerName << endl;
	outfile << "Species_Num " << z.speciesNum << endl;
	outfile << "Funds " << z.funds << endl;
	outfile << "Operating_Ticks " << z.opTicks << endl;
	outfile << "</Zoo> NULL" << endl;
	outfile << "<Asian_Elephant> NULL" << endl;
	outfile << "Quantity " << nQty << endl;
	outfile << "ID ";
	for (i = 0; i < nQty - 1; i++)
	{
		outfile << z.asEle_vec [i].id<<",";
	}
	outfile << z.asEle_vec[i].id << endl;

	outfile << "Name ";
	for (i = 0; i < nQty - 1; i++)
	{
		outfile << z.asEle_vec[i].name << ",";
	}
	outfile << z.asEle_vec[i].name << endl;

	outfile << "Birthplace ";
	for (i = 0; i < nQty - 1; i++)
	{
		outfile << z.asEle_vec[i].birthPlace << ",";
	}
	outfile << z.asEle_vec[i].birthPlace << endl;

	outfile << "Ticks ";
	for (i = 0; i < nQty - 1; i++)
	{
		outfile << z.asEle_vec[i].ticks  << ",";
	}
	outfile << z.asEle_vec[i].ticks << endl;

	outfile << "BirthTicks ";
	for (i = 0; i < nQty - 1; i++)
	{
		outfile << z.asEle_vec[i].birthTicks << ",";
	}
	outfile << z.asEle_vec[i].birthTicks << endl;

	outfile << "Price ";
	for (i = 0; i < nQty - 1; i++)
	{
		outfile << z.asEle_vec[i].price << ",";
	}
	outfile << z.asEle_vec[i].price << endl;

	outfile << "Weight ";
	for (i = 0; i < nQty - 1; i++)
	{
		outfile << z.asEle_vec[i].weight << ",";
	}
	outfile << z.asEle_vec[i].weight << endl;

	outfile << "Height ";
	for (i = 0; i < nQty - 1; i++)
	{
		outfile << z.asEle_vec[i].height << ",";
	}
	outfile << z.asEle_vec[i].height << endl;

	outfile << "Width ";
	for (i = 0; i < nQty - 1; i++)
	{
		outfile << z.asEle_vec[i].width << ",";
	}
	outfile << z.asEle_vec[i].width << endl;

	outfile << "Length ";
	for (i = 0; i < nQty - 1; i++)
	{
		outfile << z.asEle_vec[i].length << ",";
	}
	outfile << z.asEle_vec[i].length << endl;

	outfile << "Gender ";
	for (i = 0; i < nQty - 1; i++)
	{
		gender gend = z.asEle_vec[i].gd;
		if (gend == MALE)
		{
			outfile << "Male" << ",";
		}
		else if(gend == FEMALE)
		{
			outfile << "Female" << ",";
		}
	}
	gender gend = z.asEle_vec[i].gd;
	if (gend == MALE)
	{
		outfile << "Male" << endl;
	}
	else if (gend == FEMALE)
	{
		outfile << "Female" << endl;
	}

	outfile << "</Asian_Elephant> NULL" << endl;
	return true;
}

vector<string> ArchiveFile::SplitString(string str1, string str2)
{
	vector<string> sVec;
	string str;
	size_t i = 0, j = 0;
	while(j = str1.find(str2,i), j!= std::string::npos)
	{
		sVec.push_back (str1.substr(i, j - i));
		i = j+1;
	}
	sVec.push_back(str1.substr(i, str1.size()-j));
	return sVec;
}

vector<Uint> ArchiveFile::CvtStoUnVec(vector<string> sVec)
{
	vector<Uint> nVec;
	Uint unTmp;
	for (vector<string>::iterator it = sVec.begin(); it != sVec.end(); it++)
	{
		stringstream ssTmp;
		ssTmp << *it;
		ssTmp >> unTmp;
		nVec.push_back(unTmp);
	}
	return nVec;
}
