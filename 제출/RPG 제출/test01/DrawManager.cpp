#include "DrawManager.h"


DrawManager::DrawManager()
{
}

void DrawManager::DrawBox()
{
	for (int y = 0; y <= HIEGHT - 1; y++)
	{
		for (int x = 0; x <= WHITH - 2; x += 2)
		{
			gotoxy(x, y);
			if (x == 0 && y == 0)
				cout << "¦£";
			else if (((x > 0 && x < WHITH - 2) && y == 0) || (y == HIEGHT - 1 && (x > 0 && x < WHITH - 2)))
				cout << "¦¡";
			else if (y == 0 && x == WHITH - 2)
				cout << "¦¤";
			else if ((y > 0 && y < HIEGHT - 1) && (x == 0 || x == WHITH - 2))
				cout << "¦¢";
			else if (y == HIEGHT - 1 && x == 0)
				cout << "¦¦";
			else if (y == HIEGHT - 1 && x == WHITH - 2)
				cout << "¦¥";
		}
	}
}

void DrawManager::Mid_Print_Sting(string Text,int y)
{
	int Text_Length = Text.length();
	gotoxy(WHITH / 2 - Text_Length / 2, y);
	cout << Text;
}

void DrawManager::Draw_Cusor(int x,int y)
{
	gotoxy(x,y);
	cout << "¢º";
}
void DrawManager::Erase_Cusor(int x,int y)
{
	gotoxy(x,y);
	cout << "  ";
}


DrawManager::~DrawManager()
{
}
