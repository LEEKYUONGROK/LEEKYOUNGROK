#include "Wand.h"



Wand::Wand()
{
}


void Wand::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <= 30)
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
			DrawM.DrawMidText( "�ϵ� ����Ŭ�� ȿ�� �ߵ� �Ϸ� !! ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 60;	
	}
	else
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ �ϵ� ����Ŭ�� ȿ�� �ߵ� ����.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
	
}
void Wand::Draw(int h)
{

	YELLOW
		DrawM.gotoxy(WIDTH - 10, h);
		cout << m_strName << " ( WAND ) " ;
		DrawM.gotoxy(WIDTH - 13, ++h);
	cout << "���� : " << m_iPrice << " G   ���ݷ� : " << m_iWeaponAttack;
	ORIGINAL
}
Wand::~Wand()
{
	
}
