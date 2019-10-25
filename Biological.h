#pragma once
#include "Gloable.h"
#include <string>

using std::string;

/**
 * �����࣬����������������Ժͷ���
 * Biological class, include basic biological attributes and functions
 */
class Biological
{
	friend class ArchiveFile;
	friend class Zoo;
	friend void ShowStatus();
public:
	/**
	 * @brief      Ĭ�Ϲ��캯��
	 *             Default constructor function
	 */
	Biological();

	/**
	 * @brief      ���캯��
	 *             Constructor function
	 */
	Biological(Uint Id, string Name, Uint BirthTicks, string Father, string Mother);

	/**
	 * @brief      ���캯��
	 *             Constructor function
	 */
	Biological(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother);

	/**
	 * @brief      ��������
	 *             Destructor function
	 */
	virtual ~Biological();//��ʹ����������������ϵͳ���ǻ�ϳ�Ĭ����������

	/**
	 * @brief      ����
	 *             Die
	 */
	virtual void Die();

	/**
	 * @brief      ��ֳ
	 *             Breed
	 * @return     bool �ɹ�Ϊtrue��ʧ��Ϊfalse
	 *             bool true if success, false if fail
	 */
	virtual bool Breed() = 0;

	/**
	 * @brief      �ɳ�
	 *             Grow
	 */
	virtual void Grow(const Uint Ticks);

	/**
	 * @brief      ����������
	 *             Set biological ID
	 */
	inline void SetId(const Uint Id) { id = Id; }

	/**
	 * @brief      ����
	 *             Naming
	 */
	inline void Naming(const string& Name) { name = Name; }

	/**
	 * @brief      ��ȡ����
	 *             Get name
	 * @return     string ��������
	 *             string biological name
	 */
	inline string GetName() const { return name; }

	/**
	 * @brief      ��ȡ��������
	 *             Get father name
	 * @return     string ���׵�����
	 *             string father name
	 */
	inline string GetFatherName() const { return father; }

	/**
	 * @brief      ��ȡĸ������
	 *             Get mother name
	 * @return     string ĸ������
	 *             string mother name
	 */
	inline string GetMotherName() const { return mother; }

	/**
	 * @brief      ���ó����δ�
	 *             Set birth ticks
	 * @param      Ticks �����δ���
	 *             Ticks birth ticks
	 * @return     ��
	 *             void
	 */
	inline void SetBirthTicks(const Uint Ticks) { birthTicks = Ticks; }

	/**
	 * @brief      ��ȡ�����δ�
	 *             Get birth ticks
	 * @return     Uint �δ���
	 *             Uint birth ticks
	 */
	inline Uint GetBirthTicks() { return birthTicks; }

	/**
	 * @brief      �ж�����
	 *             Get birth ticks
	 * @return     bool trueΪ����falseΪ��
	 *             bool true if alive, false if dead
	 */
	virtual bool CheckLife() const = 0;

protected:
	/** ������ */
	/** Biological ID */
	Uint id;

	/** ���� */
	/** Name */
	string name;

	/** ������ */
	/** Birth place */
	string birthPlace;

	/** �����δ� */
	/** Birth ticks */
	Uint birthTicks;

	/** ����δ� */
	/** Age ticks */
	Uint ageTicks;

	/** �۸� */
	/** Price */
	Uint price;

	/** ���� */
	/** If alive */
	bool live;

	/** �������� */
	/** Father name */
	string father;

	/** ĸ������ */
	/** Mother name */
	string mother;
};

