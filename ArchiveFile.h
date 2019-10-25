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

/**
 * 存档文件类，用于载入和保存动物园信息
 * Archieve file class which used to load and save zoo information
 */
class ArchiveFile
{
public:
	/**
	 * @brief      默认构造函数
	 *             Default constructor function.
	 *
	 */
	ArchiveFile();

	/**
	 * @brief      构造函数
	 *             Constructor function.
	 * @param      strFile 文件名
	 *             strFile file name
	 */
	ArchiveFile(const string& strFile);

	/**
	 * @brief      析构函数
	 *             Destructor function.
	 *
	 */
	~ArchiveFile();

	/**
     *  @brief     设置文件名
	 *             Set the archive file name
     *  @param     strFile 文件名
	 *             strFile file name
     *  @return    无
	 *             void
     */
	void SetFileName(const string& strFile);

	/**
     *  @brief     从存档文件中载入动物园信息
	 *             Load zoo information from archive file
     *  @param     z zoo对象引用
	               z reference of the zoo object
     *  @return    bool 载入成功true，失败false
	               bool true if success, false if fail
     */
	bool Load(Zoo& z);

	/**
     *  @brief     保存动物园信息到存档文件
	 *             Save zoo information to archive file
     *  @param     z 动物园对象引用
	 *             z reference of the zoo object
     *  @return    bool 保存成功true，失败false
	 *             bool true for success, false for fail
     */
	bool Save(const Zoo& z);
private:
	/** 存档文件名 */
	/** Archive file name */
	string fileName;

	/** 输入文件流 */
	/** input file stream */
	ifstream infile;

	/** 输出文件流 */
	/** output file stream */
	ofstream outfile;

	/**
     *  @brief     将字符串按照特定的标志分成若干子字符串
	 *             Split string into several sub string via a token
     *  @param     str1 需要分割的字符串
	 *             str1 the string you want to split
     *  @param     str2 标志
	 *             str2 token
     *  @return    字符串容器
	 *             vector<string>
     */
	vector<string> SplitString(const string& str1, const string& str2);

	/**
     *  @brief     将字符串容器转换成Uint容器
	 *             Convert vector string to vector Uint
     *  @param     sVec 字符串容器对象
	 *             sVec vector string object
     *  @return    Uint容器对象
	 *             vector<Uint>
     */
	vector<Uint> CvtStoUnVec(vector<string> sVec);

	/**
     *  @brief     将字符串容器转换成布尔容器
	 *             Convert vector string to vector bool
     *  @param     sVec 字符串容器对象
	 *             sVec vector string object
     *  @return    布尔容器对象
	 *             vector<bool>
     */
	vector<bool> CvtStoBoolVec(vector<string> sVec);
};

