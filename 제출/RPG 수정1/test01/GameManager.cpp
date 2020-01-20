#include "GameManager.h"



GameManager::GameManager()
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HIEGHT + 1,  WHITH );
	system(buf);

	m_eMenu = Start_Menu;
	m_Pplayer = &m_oShop;
}

void GameManager::Game_manager()
{
	int Return_num;//커서 선택값을 반환받는 수
	int Select_Weapon,Select_Weaopn_Class;

	while (1)
	{
		switch (m_eMenu)
		{
		case Start_Menu:
			m_Omenu.Draw_Start_Menu();
			Return_num = m_Omenu.Cusor_Move_Controll(3,0.3,0.4);
			if (Return_num == 1)
			{
				m_Pplayer->Set_Player();
				m_eMenu = Main_Menu;
			}
			else if (Return_num == 2)
				m_eMenu = Load_Menu;
			else
				return;
			break;

		case Main_Menu:
			m_Omenu.Draw_Main_Menu();
			Return_num = m_Omenu.Cusor_Move_Controll(6,0.3,0.3);
			if (Return_num == 1)
				m_eMenu = Dongeon_Menu;
			else if (Return_num == 2)
			{
				m_Pplayer->Print_Player();
				system("pause");
			}
			else if (Return_num == 3)
				m_Pplayer->Print_Monster_List();
			else if (Return_num == 4)
				m_eMenu = Shop_Menu;
			else if (Return_num == 5)
				m_eMenu = Save_Menu;
			else if (Return_num == 6)
				m_eMenu = Start_Menu;
			break;

		case Dongeon_Menu:
			m_Omenu.Draw_Dongen_Menu();
			Return_num = m_Omenu.Cusor_Move_Controll(6,0.2,0.3);
			if (m_Pplayer->Fight(Return_num - 1) == true)
			{
				m_eMenu = Main_Menu;
				cout << "Player 승리";
				system("pause");
				break;
			}
			else
			{
				cout << "Player 사망";
				system("pause");
				return;
			}

		case Shop_Menu:
			m_Omenu.Draw_Shop();
			Select_Weapon = m_Omenu.Cusor_Move_Controll(4, 0.3, 0.3);//Select_Weapon = 상점에서 선택한 무기
			if (Select_Weapon >= 1 && Select_Weapon <= 3)
			{
				m_oShop.Print_Weapon_list(Select_Weapon - 1);
				Select_Weaopn_Class = m_Omenu.Cusor_Move_Controll(3, 0.4, 0.2);//Select_Weaopn_Class = 선택한 무기단계 
				m_Pplayer->Wearing_Weapon(Select_Weapon - 1, Select_Weaopn_Class - 1);
			}
			else
				m_eMenu = Main_Menu;
			break;

		case Save_Menu:
		case Load_Menu:
			//m_Omenu.Draw_Load_Menu();
			m_Pplayer->Print_Slot();
			Return_num = m_Omenu.Cusor_Move_Controll(5, 0.3, 0.2);
			if (m_eMenu == Save_Menu)
			{
				m_Pplayer->Save(Return_num);
				m_eMenu = Start_Menu;
			}
			else if (m_eMenu == Load_Menu)
			{
				m_Pplayer->Load(Return_num);
				m_eMenu = Main_Menu;
			}
			break;
		}
	}
}

GameManager::~GameManager()
{
}
