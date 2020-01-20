#pragma once
#include "DrawManager.h"

struct Player_inpomatoin
{
	string Name;
	int Lv,Power,Life,Max_Exe,Get_Exe,Glod;
}; 

class Playeer
{
protected:
	Player_inpomatoin m_Splayer;
private:
	DrawManager m_Odraw;
	Player_inpomatoin M_SMonster_list[6];
public:
	void Print_Slot();
	void Load(int index);
	void Save(int index);
	void LevelUP();
	void Print_Monster_List();
	void Print_Monser(int index);
	void Print_Player();
	void Set_Monster();
	void Set_Player();
	bool Fight(int index);
	
	virtual void Wearing_Weapon(int Select_Weapon, int Class) = 0;
	Playeer();
	~Playeer();
};
