#include "Hammer.h"



Hammer::Hammer()
{

}

void Hammer::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <= 40)
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
			DrawM.DrawMidText( "�ظ� ����� ȿ�� �ߵ� �Ϸ� !! ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 40;
	}
	else
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ �ظ� ����� ȿ�� �ߵ� ����.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
}
void Hammer::Draw(int h)
{

	YELLOW
		DrawM.gotoxy(WIDTH - 10, h);
		cout << m_strName << " ( HAMMER - ���� ) ";
		DrawM.gotoxy(WIDTH - 13, ++h);
		cout << "���� : " << m_iPrice << " G   ���ݷ� : " << m_iWeaponAttack ;
	ORIGINAL
}
Hammer::~Hammer()
{

}
