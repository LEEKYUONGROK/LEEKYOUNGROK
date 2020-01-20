#include "Playeer.h"

Playeer::Playeer()
{
	srand(time(NULL));
	Set_Monster();
}

void Playeer::Set_Player()
{	
	system("cls");
	m_Odraw.DrawBox();
	m_Odraw.Mid_Print_Sting("Player Name Set :",HIEGHT * 0.5);
	cin >> m_Splayer.Name;
	m_Splayer.Lv = 1, m_Splayer.Power = 20, m_Splayer.Max_Exe = 30, m_Splayer.Get_Exe = 0, m_Splayer.Glod = 0, m_Splayer.Life = 50;
}

void Playeer::Set_Monster()
{
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
		{
			M_SMonster_list[i].Lv = 1;
			M_SMonster_list[i].Power = 5;
			M_SMonster_list[i].Glod = 10;
			M_SMonster_list[i].Get_Exe = 30;
			M_SMonster_list[i].Life = 20;
		}
		else
		{
			M_SMonster_list[i].Lv = M_SMonster_list[i - 1].Lv;
			M_SMonster_list[i].Power = M_SMonster_list[i - 1].Power * 2;
			M_SMonster_list[i].Life = M_SMonster_list[i - 1].Life * 3;
			M_SMonster_list[i].Glod = M_SMonster_list[i - 1].Glod + 10;
			M_SMonster_list[i].Get_Exe = M_SMonster_list[i - 1].Get_Exe * 2;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			M_SMonster_list[i].Name = "´ÞÆØÀÌ";
		else if (i == 1)
			M_SMonster_list[i].Name = "ÆÄ¶õ´ÞÆØÀÌ";
		else if (i == 2)
			M_SMonster_list[i].Name = "»¡°£´ÞÆØÀÌ";
		else if (i == 3)
			M_SMonster_list[i].Name = "ÁÖÈ²¹ö¼¸";
		else if (i == 4)
			M_SMonster_list[i].Name = "»Ô¹ö¼¸";
		else if (i == 5)
			M_SMonster_list[i].Name = "Á»ºñ¹ö¼¸";
	}
}

bool Playeer::Fight(int index)
{
	int input;
	int Num;

	while (M_SMonster_list[index].Life > 1 && m_Splayer.Life > 1)
	{
		Num = rand() % 3;
		Print_Player();
		m_Odraw.Mid_Print_Sting("°¡À§ : 0, ¹ÙÀ§ : 1 º¸ : 2", HIEGHT * 0.25);
		m_Odraw.Mid_Print_Sting("===========vs===========", HIEGHT * 0.5);
		Print_Monser(index);
		m_Odraw.Mid_Print_Sting("ÀÔ·Â : ", HIEGHT * 0.5 - 2);
		cin >> input;

		if (input == Num);
		else if (input == 0 && Num == 2)
			M_SMonster_list[index].Life -= m_Splayer.Power;
		else if (input == 0 && Num == 1)
			m_Splayer.Life -= M_SMonster_list[index].Power;
		else if(input == 1 && Num == 0)
			M_SMonster_list[index].Life -= m_Splayer.Power;
		else if(input == 1 && Num == 2)
			m_Splayer.Life -= M_SMonster_list[index].Power;
		else if(input == 2 && Num == 0)
			m_Splayer.Life -= M_SMonster_list[index].Power;
		else if(input == 2 && Num == 1)
			M_SMonster_list[index].Life -= m_Splayer.Power;
	}
	if (M_SMonster_list[index].Life < 1)//Player ½Â¸® 
	{
		m_Splayer.Glod += M_SMonster_list[index].Glod;
		m_Splayer.Get_Exe += M_SMonster_list[index].Get_Exe;
		LevelUP();
		Set_Monster();
		return true;
	}
	else if (m_Splayer.Life < 1)//ÆÐ¹è
		return false;
}
void Playeer::Print_Slot()
{
	ifstream load;
	string tmp;
	string Print_tmp;
	int Print_Hight = HIEGHT * 0.2;
	
	system("cls");
	m_Odraw.DrawBox();
	for (int i = 1; i <= 5; i++)
	{
		tmp = "Player";
		tmp += to_string(i);
		tmp += ".txt";

		Print_tmp = "½½·Ô";
		Print_tmp += to_string(i);
		
		load.open(tmp);
		if (load.is_open())
		{
			Print_tmp += ": O";
			m_Odraw.Mid_Print_Sting(Print_tmp, Print_Hight);
			load.close();
		}
		else
		{
			Print_tmp += ": X";
			m_Odraw.Mid_Print_Sting(Print_tmp, Print_Hight);
		}
		Print_Hight += HIEGHT * 0.1;
	}
}
void Playeer::Load(int index)
{
	ifstream load;
	string tmp = "Player";
	tmp += to_string(index);
	tmp += ".txt";

	load.open(tmp);
	while (!load.eof())
	{
		load >> m_Splayer.Name;
		load >> m_Splayer.Lv;
		load >> m_Splayer.Power;
		load >> m_Splayer.Life;
		load >> m_Splayer.Max_Exe;
		load >> m_Splayer.Get_Exe;
		load >> m_Splayer.Glod;
	}

}
void Playeer::Save(int index)
{
	ofstream save;
	string tmp = "Player";
	tmp += to_string(index);
	tmp += ".txt";

	save.open(tmp);
	if (save.is_open())
	{
		save << m_Splayer.Name <<" "<< m_Splayer.Lv << endl;
		save << m_Splayer.Power << " " << m_Splayer.Life << endl;
		save << m_Splayer.Max_Exe <<" "<< m_Splayer.Get_Exe << endl;
		save << m_Splayer.Glod;
		save.close();
	}
	cout << "ÀúÀå ¿Ï·á";
	system("pause");
}
void Playeer::LevelUP()
{
	while (m_Splayer.Get_Exe >= m_Splayer.Max_Exe)
	{
		m_Splayer.Lv++;
		m_Splayer.Max_Exe *= 2;
		m_Splayer.Get_Exe = 0;
		m_Splayer.Power += 5;
		m_Splayer.Life += 10;
	}

}
void Playeer::Print_Monser(int index)
{
	string tmp;
	tmp = "Monster Name : ";
	tmp += M_SMonster_list[index].Name;
	m_Odraw.Mid_Print_Sting(tmp, HIEGHT - 10);

	tmp = "°ø°Ý·Â = ";
	tmp += to_string(M_SMonster_list[index].Power);
	tmp += "  »ý¸í·Â = ";
	tmp += to_string(M_SMonster_list[index].Life);
	m_Odraw.Mid_Print_Sting(tmp, HIEGHT - 9);

	tmp = "È¹µæ °æÇèÄ¡ = ";
	tmp += to_string(M_SMonster_list[index].Get_Exe);
	tmp += " °ñµå : ";
	tmp += to_string(M_SMonster_list[index].Glod);
	m_Odraw.Mid_Print_Sting(tmp, HIEGHT - 8);
}
void Playeer::Print_Player()
{
	int Print_Hieght = 1;
	string tmp;
	system("cls");
	m_Odraw.DrawBox();

	tmp = "USER NAME : ";
	tmp += m_Splayer.Name;
	m_Odraw.Mid_Print_Sting(tmp, Print_Hieght++);

	tmp = "(LV) : ";
	tmp += to_string(m_Splayer.Lv);
	m_Odraw.Mid_Print_Sting(tmp, Print_Hieght++);

	tmp = "°ø°Ý·Â = ";
	tmp += to_string(m_Splayer.Power);
	tmp += "  »ý¸í·Â = ";
	tmp += to_string(m_Splayer.Life);
	m_Odraw.Mid_Print_Sting(tmp, Print_Hieght++);

	tmp = "ÃÖ´ë °æÇèÄ¡ = ";
	tmp += to_string(m_Splayer.Max_Exe);
	tmp += " ÇöÀç °æÇèÄ¡ = ";
	tmp += to_string(m_Splayer.Get_Exe);
	m_Odraw.Mid_Print_Sting(tmp, Print_Hieght++);

	tmp = "°ñµå = ";
	tmp += to_string(m_Splayer.Glod);
	m_Odraw.Mid_Print_Sting(tmp, Print_Hieght++);
}
void Playeer::Print_Monster_List()
{
	string tmp;
	int Print_Heiht = 1;
	system("cls");
	m_Odraw.DrawBox();

	for (int i = 0; i < 6; i++)
	{
		tmp = "Monster Name : ";
		tmp += M_SMonster_list[i].Name;
		m_Odraw.Mid_Print_Sting(tmp, Print_Heiht ++);

		tmp = "°ø°Ý·Â = ";
		tmp += to_string(M_SMonster_list[i].Power);
		tmp += "  »ý¸í·Â = ";
		tmp += to_string(M_SMonster_list[i].Life);
		m_Odraw.Mid_Print_Sting(tmp, Print_Heiht ++);

		tmp = "È¹µæ °æÇèÄ¡ = ";
		tmp += to_string(M_SMonster_list[i].Get_Exe);
		tmp += " °ñµå : ";
		tmp += to_string(M_SMonster_list[i].Glod);
		m_Odraw.Mid_Print_Sting(tmp, Print_Heiht ++);
		Print_Heiht++;
	}
	system("pause");
}
Playeer::~Playeer()
{
}
