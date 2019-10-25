#pragma once
#include "Biological.h"

//�����
class Animal :
	public Biological
{
	friend class ArchiveFile;
	friend class Zoo;
	friend void ShowStatus();
public:
	Animal();
	Animal(Uint Id, string Name, Uint BirthTicks, string Father, string Mother, gender Gd);
	Animal(Uint Id, string Name, string BirthPlace, Uint BirthTicks, Uint AgeTicks, Uint Price, bool Live, string Father, string Mother,
		Uint Weight, Uint Height, Uint Width, Uint Length, gender Gd, Uint HungryTicks, Uint PregTicks, Uint MateTicks, bool Preg);
	virtual ~Animal();

	/**
	 * @brief      ��ʳ
	 *             Get birth ticks
	 * @return     Uint ʳ�ﻨ��
	 *             Uint birth ticks
	 */
	virtual Uint Eat() = 0;

	/**
	 * @brief      ��й
	 *             Excrete
	 */
	virtual void Excrete() = 0;

	/**
	 * @brief      ��鼢�����
	 *             Check hungry message
	 * @return     hungryMsg ������Ϣ
	 *             hungryMsg hungry message
	 */
	virtual hungryMsg CheckHungry() const = 0;

	/**
	 * @brief      �жϻ���
	 *             Check if pregnant
	 * @return     bool trueΪ���У�falseΪδ����
	 *             bool true if pregnant, false if not pregnant
	 */
	virtual inline bool IsPreg() const{ return preg; }

	/**
	 * @brief      �ж��Ƿ�ֳ
	 *             Check if breeding
	 * @return     bool trueΪ׼����ֳ��falseΪδ׼����ֳ
	 *             Uint true if breeding, false if not breeding
	 */
	virtual bool CheckBreed() const = 0;

	/**
	 * @brief      �����Ա�
	 *             Ser animal gender
	 * @param      gend �����Ա�
	 *             gend animal gender
	 */
	inline void SetGender(const gender& gend) { gd = gend; }

	/**
	 * @brief      ��ȡ�����Ա�
	 *             Get animal gender
	 * @return     gender �����Ա�
	 *             gender animal gender
	 */
	inline gender GetGender() { return gd; }
protected:
	/** ���� */
	/** Body weight */
	Uint weight;

	/** ��� */
	/** Body height */
	Uint height;

	/** ��� */
	/** Body width */
	Uint width;

	/** �� */
	/** Body length */
	Uint length;

	/** �Ա� */
	/** Gender */
	gender gd;

	/** �����δ� */
	/** Hungry ticks */
	Uint hungryTicks;

	/** ���еδ� */
	/** Pregnant ticks */
	Uint pregTicks;

	/** ����δ� */
	/** Mate ticks */
	Uint mateTicks;

	/** �Ƿ��� */
	/** If pregnant */
	bool preg;
};

