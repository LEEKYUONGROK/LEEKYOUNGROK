#pragma once
#include"Menu.h"
#include"Playeer.h"
#include"Shop.h"

class GameManager
{
private:
	enum_Menu m_eMenu;
	Menu m_Omenu;
	Playeer* m_Pplayer;
	Shop m_oShop;
public:
	void Game_manager();
	GameManager();
	~GameManager();
};

