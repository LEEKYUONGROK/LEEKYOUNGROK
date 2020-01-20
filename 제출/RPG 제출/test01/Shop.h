#pragma once
#include "Playeer.h"

enum Weapon
{
	Gun,
	Hemer,
	Sword,
	Weapon_End = Sword
};
struct Weapon_inpomation
{
	int Weapon_Power,Weapon_Risk,Weapon_Glod;
};
class Shop : public Playeer
{
private:
	DrawManager m_Odarw;
	Weapon_inpomation Weapon_list[3][3];
public:
	void Wearing_Weapon(int Select_Weapon,int Class);
	void Print_Weapon_list(int Select);
	void Set_Weapon_list();
	Shop();
	~Shop();
};

