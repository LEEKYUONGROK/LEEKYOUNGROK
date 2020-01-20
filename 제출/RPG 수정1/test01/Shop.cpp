#include "Shop.h"


Shop::Shop()
{
	Set_Weapon_list();
}
void Shop::Wearing_Weapon(int Select_Weapon,int Class)
{
	if (Weapon_list[Select_Weapon][Class].Weapon_Glod > m_Splayer.Glod)
		cout << "골드가 부족합니다" << endl;
	else
	{
		m_Splayer.Glod -= Weapon_list[Select_Weapon][Class].Weapon_Glod;
		m_Splayer.Power += Weapon_list[Select_Weapon][Class].Weapon_Power;
		if (Select_Weapon == Hemer)
			m_Splayer.Life -= Weapon_list[Select_Weapon][Class].Weapon_Risk;
		cout << "구입 성공" << endl;
	}
	system("pause");
}

void Shop::Print_Weapon_list(int Select)
{
	system("cls");
	string tmp;
	float Print_HIGHT = 0.2;

	if (Select == Gun)
		m_Odarw.Mid_Print_Sting("총 리스트", HIEGHT * 0.1);
	if (Select == Hemer)
		m_Odarw.Mid_Print_Sting("헤머 리스트", HIEGHT * 0.1);
	if (Select == Sword)
		m_Odarw.Mid_Print_Sting("소드 리스트", HIEGHT * 0.1);

	for (int i = 0; i < 3; i++)
	{
		tmp = to_string(i + 1);
		tmp += "단계";
		m_Odarw.Mid_Print_Sting(tmp, HIEGHT * Print_HIGHT);
		tmp = "공격력 : ";
		tmp += to_string(Weapon_list[Select][i].Weapon_Power);
		tmp += " 리스크 : ";

		if (Select == Gun)
		{
			tmp += to_string(Weapon_list[Select][i].Weapon_Risk);
			m_Odarw.Mid_Print_Sting(tmp, HIEGHT * Print_HIGHT + 1);
		}
		if (Select == Hemer)
		{
			tmp += "생명력 -";
			tmp += to_string(Weapon_list[Select][i].Weapon_Risk);
			m_Odarw.Mid_Print_Sting(tmp, HIEGHT * Print_HIGHT + 1);
		}
		if (Select == Sword)
		{
			tmp += "골드 -";
			tmp += to_string(Weapon_list[Select][i].Weapon_Risk);
			m_Odarw.Mid_Print_Sting(tmp, HIEGHT * Print_HIGHT + 1);
		}
		tmp = "골드 : ";
		tmp += to_string(Weapon_list[Select][i].Weapon_Glod);
		m_Odarw.Mid_Print_Sting(tmp, HIEGHT * Print_HIGHT + 2);

		Print_HIGHT += 0.1;
	}
}

void Shop::Set_Weapon_list()
{
	for (int i = 0; i <= Weapon_End; i++)
	{
		for (int j = 0; j <= Weapon_End; j++)
		{
			Weapon_list[i][j].Weapon_Power = 10;
			Weapon_list[i][j].Weapon_Risk = 0;
			Weapon_list[i][j].Weapon_Glod = 30;
			if (i == Hemer)
			{
				Weapon_list[i][j].Weapon_Power += 20;
				Weapon_list[i][j].Weapon_Risk += 15;
				Weapon_list[i][j].Weapon_Glod += 10;
			}
			else if (i == Sword)
			{
				Weapon_list[i][j].Weapon_Power += 10;
				Weapon_list[i][j].Weapon_Risk += 10;
				Weapon_list[i][j].Weapon_Glod = Weapon_list[i][j].Weapon_Glod + Weapon_list[i][j].Weapon_Risk;
			}

			if (i == Gun && j > 0)
			{
				Weapon_list[i][j].Weapon_Power = Weapon_list[i][j - 1].Weapon_Power + 10;
				Weapon_list[i][j].Weapon_Risk = Weapon_list[i][j - 1].Weapon_Risk;
				Weapon_list[i][j].Weapon_Glod = Weapon_list[i][j - 1].Weapon_Glod + 50;
			}
			else if (i == Hemer && j > 0)
			{
				Weapon_list[i][j].Weapon_Power = Weapon_list[i][j - 1].Weapon_Power + 30;
				Weapon_list[i][j].Weapon_Risk = Weapon_list[i][j - 1].Weapon_Risk + 15;
				Weapon_list[i][j].Weapon_Glod = Weapon_list[i][j - 1].Weapon_Glod + 60;
			}
			else if (i == Sword && j > 0)
			{
				Weapon_list[i][j].Weapon_Power = Weapon_list[i][j - 1].Weapon_Power + 20;
				Weapon_list[i][j].Weapon_Risk = Weapon_list[i][j - 1].Weapon_Risk + 10;
				Weapon_list[i][j].Weapon_Glod = Weapon_list[i][j - 1].Weapon_Glod + Weapon_list[i][j - 1].Weapon_Risk + 60;
			}
		}
	}
}

Shop::~Shop()
{
}
