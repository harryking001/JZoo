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
 * �浵�ļ��࣬��������ͱ��涯��԰��Ϣ
 * Archieve file class which used to load and save zoo information
 */
class ArchiveFile
{
public:
	/**
	 * @brief      Ĭ�Ϲ��캯��
	 *             Default constructor function.
	 *
	 */
	ArchiveFile();

	/**
	 * @brief      ���캯��
	 *             Constructor function.
	 * @param      strFile �ļ���
	 *             strFile file name
	 */
	ArchiveFile(const string& strFile);

	/**
	 * @brief      ��������
	 *             Destructor function.
	 *
	 */
	~ArchiveFile();

	/**
     *  @brief     �����ļ���
	 *             Set the archive file name
     *  @param     strFile �ļ���
	 *             strFile file name
     *  @return    ��
	 *             void
     */
	void SetFileName(const string& strFile);

	/**
     *  @brief     �Ӵ浵�ļ������붯��԰��Ϣ
	 *             Load zoo information from archive file
     *  @param     z zoo��������
	               z reference of the zoo object
     *  @return    bool ����ɹ�true��ʧ��false
	               bool true if success, false if fail
     */
	bool Load(Zoo& z);

	/**
     *  @brief     ���涯��԰��Ϣ���浵�ļ�
	 *             Save zoo information to archive file
     *  @param     z ����԰��������
	 *             z reference of the zoo object
     *  @return    bool ����ɹ�true��ʧ��false
	 *             bool true for success, false for fail
     */
	bool Save(const Zoo& z);
private:
	/** �浵�ļ��� */
	/** Archive file name */
	string fileName;

	/** �����ļ��� */
	/** input file stream */
	ifstream infile;

	/** ����ļ��� */
	/** output file stream */
	ofstream outfile;

	/**
     *  @brief     ���ַ��������ض��ı�־�ֳ��������ַ���
	 *             Split string into several sub string via a token
     *  @param     str1 ��Ҫ�ָ���ַ���
	 *             str1 the string you want to split
     *  @param     str2 ��־
	 *             str2 token
     *  @return    �ַ�������
	 *             vector<string>
     */
	vector<string> SplitString(const string& str1, const string& str2);

	/**
     *  @brief     ���ַ�������ת����Uint����
	 *             Convert vector string to vector Uint
     *  @param     sVec �ַ�����������
	 *             sVec vector string object
     *  @return    Uint��������
	 *             vector<Uint>
     */
	vector<Uint> CvtStoUnVec(vector<string> sVec);

	/**
     *  @brief     ���ַ�������ת���ɲ�������
	 *             Convert vector string to vector bool
     *  @param     sVec �ַ�����������
	 *             sVec vector string object
     *  @return    ������������
	 *             vector<bool>
     */
	vector<bool> CvtStoBoolVec(vector<string> sVec);
};

