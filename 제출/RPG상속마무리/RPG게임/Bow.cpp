#include "Bow.h"

Bow::Bow()
{
}

void Bow::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <= 100) // Ȯ�������� 100
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText( "���� ũ��Ƽ�� ȿ�� �ߵ� �Ϸ� !! ", WIDTH, HEIGHT*0.5);
	ORIGINAL
		m_iRandom = 50; // ����Ȯ�������� ���ݷ� 50 �߰�
	}	
	else
	{
		YELLOW
		DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ ���� ũ��Ƽ�� ȿ�� �ߵ� ����.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
}
void Bow::Draw(int h)
{
	YELLOW
	DrawM.gotoxy(WIDTH - 10, h);
	cout << m_strName << " ( BOW - ���Ÿ� ) ";
	DrawM.gotoxy(WIDTH - 13, ++h);
	cout << "���� : " << m_iPrice << " G   ���ݷ� : " << m_iWeaponAttack;
	ORIGINAL
}


Bow::~Bow()
{

}
