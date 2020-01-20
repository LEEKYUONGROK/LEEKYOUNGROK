#include "Menu.h"
#include "Playeer.h"

Menu::Menu()
{
}

void Menu::Draw_Start_Menu()
{
	system("cls");
	m_OdrawMenu.DrawBox();
	m_OdrawMenu.Mid_Print_Sting("¡Ú¡Ù TEXT RPG GAME ¡Ù¡Ú", HIEGHT * 0.3);
	m_OdrawMenu.Mid_Print_Sting("1.NEW Game", HIEGHT * 0.4);
	m_OdrawMenu.Mid_Print_Sting("2.Load Game", HIEGHT * 0.5);
	m_OdrawMenu.Mid_Print_Sting("3.Game Exit", HIEGHT * 0.6);
}

int Menu::Cusor_Move_Controll(int Max_Move,float cusor_pointX,float cusor_pointY)
{
	int Move_Conuter = 1;
	char ch;

	m_OdrawMenu.Draw_Cusor(WHITH * cusor_pointX, HIEGHT * cusor_pointY);
	while (1)
	{
		ch = getch();
		switch (ch)
		{
		case 'w':
		case 'W':
			if (Move_Conuter == 1)
				break;
			else
			{
				m_OdrawMenu.Erase_Cusor(WHITH * cusor_pointX,HIEGHT * cusor_pointY);
				cusor_pointY -= 0.1;
				Move_Conuter -= 1;
				break;
			}
		case 's':
		case 'S':
			if (Move_Conuter == Max_Move)
				break;
			else
			{
				m_OdrawMenu.Erase_Cusor(WHITH * cusor_pointX,HIEGHT * cusor_pointY);
				cusor_pointY += 0.1;
				Move_Conuter += 1;
				break;
			}
		case ENTER:
			return Move_Conuter;
		}
		m_OdrawMenu.Draw_Cusor(WHITH * cusor_pointX,HIEGHT * cusor_pointY);
	}
}

void Menu::Draw_Main_Menu()
{
	system("cls");
	m_OdrawMenu.DrawBox();
	m_OdrawMenu.Mid_Print_Sting("¡Ú¡Ù MENU ¡Ù¡Ú", HIEGHT * 0.2);
	m_OdrawMenu.Mid_Print_Sting("DONGEON", HIEGHT * 0.3);
	m_OdrawMenu.Mid_Print_Sting("PLAYER INFO", HIEGHT * 0.4);
	m_OdrawMenu.Mid_Print_Sting("MONSTER INFO", HIEGHT * 0.5);
	m_OdrawMenu.Mid_Print_Sting("WEAPON SHOP", HIEGHT * 0.6);
	m_OdrawMenu.Mid_Print_Sting("SAVE", HIEGHT * 0.7);
	m_OdrawMenu.Mid_Print_Sting("EXIT", HIEGHT * 0.8);
}
void Menu::Draw_Shop()
{
	system("cls");
	m_OdrawMenu.DrawBox();
	m_OdrawMenu.Mid_Print_Sting("¡Ú¡Ù¡Û »óÁ¡ ¡Û¡Ù¡Ú", HIEGHT * 0.2);
	m_OdrawMenu.Mid_Print_Sting("1.ÃÑ", HIEGHT * 0.3);
	m_OdrawMenu.Mid_Print_Sting("2.Çì¸Ó", HIEGHT * 0.4);
	m_OdrawMenu.Mid_Print_Sting("3.°Ë", HIEGHT * 0.5);
	m_OdrawMenu.Mid_Print_Sting("4.Exit", HIEGHT * 0.6);
}
void Menu::Draw_Load_Menu()
{
	system("cls");
	m_OdrawMenu.DrawBox();
	m_OdrawMenu.Mid_Print_Sting("1. ¹ø ½½·Ô : ", HIEGHT * 0.2);
	m_OdrawMenu.Mid_Print_Sting("2. ¹ø ½½·Ô : ", HIEGHT * 0.3);
	m_OdrawMenu.Mid_Print_Sting("3. ¹ø ½½·Ô : ", HIEGHT * 0.4);
	m_OdrawMenu.Mid_Print_Sting("4. ¹ø ½½·Ô : ", HIEGHT * 0.5);
	m_OdrawMenu.Mid_Print_Sting("5. ¹ø ½½·Ô : ", HIEGHT * 0.6);
}
void Menu::Draw_Dongen_Menu()
{
	system("cls");
	m_OdrawMenu.DrawBox();
	m_OdrawMenu.Mid_Print_Sting("¡Ú¡Ù¡Û´øÀü¡Û¡Ù¡Ú", HIEGHT * 0.2);
	m_OdrawMenu.Mid_Print_Sting("1.Ãþ ´øÀü : [´ÞÆØÀÌ]    ", HIEGHT * 0.3);
	m_OdrawMenu.Mid_Print_Sting("2.Ãþ ´øÀü : [ÆÄ¶õ´ÞÆØÀÌ]", HIEGHT * 0.4);
	m_OdrawMenu.Mid_Print_Sting("3.Ãþ ´øÀü : [»¡°­´ÞÆØÀÌ]", HIEGHT * 0.5);
	m_OdrawMenu.Mid_Print_Sting("4.Ãþ ´øÀü : [ÁÖÈ²¹ö¼¸]  ", HIEGHT * 0.6);
	m_OdrawMenu.Mid_Print_Sting("5.Ãþ ´øÀü : [»Ô¹ö¼¸]    ", HIEGHT * 0.7);
	m_OdrawMenu.Mid_Print_Sting("6.Ãþ ´øÀü : [Á»ºñ¹ö¼¸]  ", HIEGHT * 0.8);
}
Menu::~Menu()
{
}
