#include "Gun.h"



Gun::Gun()
{
}
void Gun::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <= 30)
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
			DrawM.DrawMidText( "�� ġ��Ÿ ȿ�� �ߵ� �Ϸ� !! ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 80;
	}
	else
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ �� ġ��Ÿ ȿ�� �ߵ� ����.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
}

void Gun::Draw(int h)
{

	YELLOW
		DrawM.gotoxy(WIDTH - 10, h);
		cout << m_strName << " ( GUN - ���Ÿ� ) ";	
		DrawM.gotoxy(WIDTH - 13, ++h);
		cout << "���� : " << m_iPrice << " G   ���ݷ� : " << m_iWeaponAttack ;
	ORIGINAL
}

Gun::~Gun()
{
}
