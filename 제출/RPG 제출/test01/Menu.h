#pragma once
#include "DrawManager.h"

class Menu
{
private:
	DrawManager m_OdrawMenu;
	int m_iCusor_Move_Counter;
public:
	int Cusor_Move_Controll(int index,float cusor_pointX,float cusor_pointY);
	void Draw_Load_Menu();
	void Draw_Shop();
	void Draw_Dongen_Menu();
	void Menu_Manager();
	void Draw_Start_Menu();
	void Draw_Main_Menu();
	Menu();
	~Menu();
};

