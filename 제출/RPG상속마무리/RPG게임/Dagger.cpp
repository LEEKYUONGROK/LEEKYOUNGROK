#include "Dagger.h"



Dagger::Dagger()
{

}

void Dagger::Show()
{
	m_iRandom = (rand() % 100) + 1;
	if (m_iRandom <=40)
	{
		YELLOW
			DrawM.BoxErase(WIDTH, HEIGHT);
			DrawM.DrawMidText( "��� �Ŀ���Ʈ����ũ ȿ�� �ߵ� �Ϸ� !! ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 30;
	}
	else
	{
		YELLOW
		DrawM.BoxErase(WIDTH, HEIGHT);
		DrawM.DrawMidText("( T-T)/ ��� �Ŀ���Ʈ����ũ ȿ�� �ߵ� ����.. ", WIDTH, HEIGHT*0.5);
		ORIGINAL
			m_iRandom = 0;
	}
}
void Dagger::Draw(int h)
{
	YELLOW
	DrawM.gotoxy(WIDTH-10, h);
	cout << m_strName << " ( DAGGER - ���� ) " ;
	DrawM.gotoxy(WIDTH-13, ++h);
	cout << "���� : " << m_iPrice << " G   ���ݷ� : " << m_iWeaponAttack;
	ORIGINAL
}
Dagger::~Dagger()
{
}
