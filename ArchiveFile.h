#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include "Zoo.h"
using std::endl;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::string;
using std::size_t;


class ArchiveFile
{
public:
	ArchiveFile();
	ArchiveFile(const string& strFile);
	~ArchiveFile();
	void SetFileName(const string& strFile);
	bool Load(Zoo& z);
	bool Save(const Zoo& z);
private:
	string fileName;
	ifstream infile;
	ofstream outfile;
	vector<string> SplitString(string str1, string str2);
	vector<Uint> CvtStoUnVec(vector<string>);
	vector<bool> CvtStoBoolVec(vector<string> sVec);
};

