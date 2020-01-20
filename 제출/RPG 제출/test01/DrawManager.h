#pragma once
#include"FileInclude.h"

class DrawManager
{
public:
	void Draw_Cusor(int y,int x);
	void Erase_Cusor(int x,int y);
	void Mid_Print_Sting(string Text,int y);
	void DrawBox();
	DrawManager();
	void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	~DrawManager();
};

