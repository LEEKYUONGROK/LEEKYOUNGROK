#include "Sword.h"



Sword::Sword()
{
}

void Sword::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <= 30)
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
			DrawM.DrawMidText( "�ҵ� ������� ȿ�� �ߵ� �Ϸ� !! ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 70;
	}
	else
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ �ҵ� ������� ȿ�� �ߵ� ����.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
}
void Sword::Draw(int h)
{

	YELLOW
	DrawM.gotoxy(WIDTH - 10, h);
	cout << m_strName << " ( SWORD - ���� ) " ;
	DrawM.gotoxy(WIDTH - 13, ++h);
	cout << "���� : " << m_iPrice << " G   ���ݷ� : " << m_iWeaponAttack ;
	ORIGINAL
}


Sword::~Sword()
{

}
