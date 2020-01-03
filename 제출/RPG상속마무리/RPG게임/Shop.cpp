#include "Shop.h"



Shop::Shop()
{
	m_iSelectWAttack = 0;
	m_iSelectWGold = 0;
	b = N;
	m_bFlag = false;
	SetWeapons();
}
//////////////////////////////////////////////Set FUNC/////////////////////////////////////////////////////////////
void Shop::SetWeapons()
{
	ofstream Save;
	Save.open("BowList.txt"); // ���� ����
	if (Save.is_open())
	{
		Save << "5" << endl;
		Save << "5 ����Ʈ���� 10 20" << endl;
		Save << "5 ũ�ν����� 15 30" << endl;
		Save << "5 ��ź�Ƶ�Ʈ 30 60" << endl;
		Save << "5 ��ǳ�ǿ��� 50 100" << endl;
		Save << "5 �������巹�� 150 300" << endl;
		Save.close();
	}

	Save.open("DaggerList.txt"); // ��� ����
	if (Save.is_open())
	{
		Save << "6" << endl;
		Save << "1 �̴ϴ�� 5 20" << endl;
		Save << "1 �ǹ���� 10 40" << endl;
		Save << "1 ����� 30 120" << endl;
		Save << "1 �÷�Ƽ�Ѵ�� 50 200" << endl;
		Save << "1 ���̾ƴ�� 80 320" << endl;
		Save << "1 �������� 150 350" << endl;
		Save.close();
	}

	Save.open("GunList.txt"); // �� ����
	if (Save.is_open())
	{
		Save << "4" << endl;
		Save << "2 ������ 15 30" << endl;
		Save << "2 ������ 25 50" << endl;
		Save << "2 ������ 40 80" << endl;
		Save << "2 ���¶��̴� 120 240" << endl;

		Save.close();
	}

	Save.open("HammerList.txt"); // �ظ� ����
	if (Save.is_open())
	{
		Save << "5" << endl;
		Save << "6 ��ö��ġ 30 70" << endl;
		Save << "6 �丣�Ǹ�ġ 50 110" << endl;
		Save << "6 �̽������� 75 170" << endl;
		Save << "6 ���Ŭ���� 150 320" << endl;
		Save << "6 �������� 210 450" << endl;
		Save.close();
	}

	Save.open("SwordList.txt"); // �ҵ� ����
	if (Save.is_open())
	{
		Save << "5" << endl;
		Save << "3 �ǹ��ҵ� 13 30" << endl;
		Save << "3 ��������� 33 70" << endl;
		Save << "3 �ֵ��ν� 45 100" << endl;
		Save << "3 ����� 80 180" << endl;
		Save << "3 ����ҵ� 150 350" << endl;
		Save.close();
	}

	Save.open("WandList.txt"); // �ϵ� ����
	if (Save.is_open())
	{
		Save << "5" << endl;
		Save << "4 ���������� 12 20" << endl;
		Save << "4 ��������� 25 40" << endl;
		Save << "4 ���丣�ǹ�� 40 70" << endl;
		Save << "4 ��ȣũ��Ʈ 85 150" << endl;
		Save << "4 ������������ 180 320" << endl;
		Save.close();
	}
	SetDaggers();
	SetBows();
	SetWands();
	SetSwords();
	SetHammers();
	SetGuns();
}
void Shop::SetDaggers()
{
	int Count; // ���� ���� ���� ����'
	string tmpName;
	int tmpPri;
	int tmpAtt;
	int tmpTy;
	ifstream Load;
	Load.open("DaggerList.txt");
	Load >> Count;
	for (int i = 0; i < Count; i++)
	{
		Load >> tmpTy; // �׳� ��Ƶδ� �� 
		Load >> tmpName;
		Load >> tmpAtt;
		Load >> tmpPri;
		Daggers[i].Set(tmpName, tmpPri, tmpAtt, WDagger);
	}
	Load.close();
}
void Shop::SetBows()
{
	int Count; // ���� ���� ���� ����'
	string tmpName;
	int tmpPri;
	int tmpAtt;
	int tmpTy;
	ifstream Load;
	Load.open("BowList.txt");
	Load >> Count;
	for (int i = 0; i < Count; i++)
	{
		Load >> tmpTy; // �׳� ��Ƶδ� �� 
		Load >> tmpName;
		Load >> tmpAtt;
		Load >> tmpPri;
		Bows[i].Set(tmpName, tmpPri, tmpAtt, WBow);
	}
	Load.close();
}
void Shop::SetWands()
{
	int Count; // ���� ���� ���� ����'
	string tmpName;
	int tmpPri;
	int tmpAtt;
	int tmpTy;
	ifstream Load;
	Load.open("WandList.txt");
	Load >> Count;
	for (int i = 0; i < Count; i++)
	{
		Load >> tmpTy; // �׳� ��Ƶδ� �� 
		Load >> tmpName;
		Load >> tmpAtt;
		Load >> tmpPri;
		Wands[i].Set(tmpName, tmpPri, tmpAtt, WWand);
	}
	Load.close();
}
void Shop::SetSwords()
{
	int Count; // ���� ���� ���� ����'
	string tmpName;
	int tmpPri;
	int tmpAtt;
	int tmpTy;
	ifstream Load;
	Load.open("SwordList.txt");
	Load >> Count;
	for (int i = 0; i < Count; i++)
	{
		Load >> tmpTy; // �׳� ��Ƶδ� �� 
		Load >> tmpName;
		Load >> tmpAtt;
		Load >> tmpPri;
		Swords[i].Set(tmpName, tmpPri, tmpAtt, WSword);
	}
	Load.close();
}
void Shop::SetHammers()
{
	int Count; // ���� ���� ���� ����'
	string tmpName;
	int tmpPri;
	int tmpAtt;
	int tmpTy;
	ifstream Load;
	Load.open("HammerList.txt");
	Load >> Count;
	for (int i = 0; i < Count; i++)
	{
		Load >> tmpTy; // �׳� ��Ƶδ� �� 
		Load >> tmpName;
		Load >> tmpAtt;
		Load >> tmpPri;
		Hammers[i].Set(tmpName, tmpPri, tmpAtt, WHammer);
	}
	Load.close();

}
void Shop::SetGuns()
{
	int Count; // ���� ���� ���� ����'
	string tmpName;
	int tmpPri;
	int tmpAtt;
	int tmpTy;
	ifstream Load;
	Load.open("GunList.txt");
	Load >> Count;
	for (int i = 0; i < Count; i++)
	{
		Load >> tmpTy; // �׳� ��Ƶδ� �� 
		Load >> tmpName;
		Load >> tmpAtt;
		Load >> tmpPri;
		Guns[i].Set(tmpName, tmpPri, tmpAtt, WGun);
	}
	Load.close();
}
//////////////////////////////////////////////Show FUNC/////////////////////////////////////////////////////////////
void Shop::ShowShop()
{
	int iSelect;

		m_iSelectWAttack = 0;
		m_iSelectWGold = 0;
		DrawManager.BoxErase(WIDTH - 2, HEIGHT - 1);
		DrawManager.DrawMidText("�ڡڡ� WEAPON SHOP �ڡڡ�", WIDTH, HEIGHT * 0.1);
		YELLOW
		DrawManager.DrawMidText("DAGGER", WIDTH, HEIGHT*0.2);
		DrawManager.DrawMidText("GUN", WIDTH, HEIGHT*0.3);
		DrawManager.DrawMidText("SWORD", WIDTH, HEIGHT*0.4);
		DrawManager.DrawMidText("WAND", WIDTH, HEIGHT*0.5);
		DrawManager.DrawMidText("BOW", WIDTH, HEIGHT*0.6);
		DrawManager.DrawMidText("HAMMER", WIDTH, HEIGHT*0.7);
		ORIGINAL
		DrawManager.DrawMidText("BACK", WIDTH, HEIGHT*0.8);
		iSelect = DrawManager.MenuSelectCursor(7, 3, 10, HEIGHT*0.2);

		switch (iSelect)
		{
		case WDagger:
			ShowDaggers();
			break;
		case WGun:
			ShowGuns();
			break;
		case WSword:
			ShowSwords();
			break;
		case WWand:
			ShowWands();
			break;
		case WBow:
			ShowBows();
			break;
		case WHammer:
			ShowHammers();
			break;
		case 7:
			m_bFlag = false;
			return ;
		default:
			break;
		}
}
void Shop::ShowDaggers()
{
	int iSelect;
	int h = HEIGHT * 0.2;
	DrawManager.BoxErase(WIDTH, HEIGHT - 1);
	DrawManager.DrawMidText("Dagger Shop", WIDTH, HEIGHT * 0.1);
	for (int i = 0; i < 6; i++)
	{
		Daggers[i].Draw(h);
		h += 3;
	}
	DrawManager.DrawMidText("EXIT", WIDTH, HEIGHT * 0.8);
	iSelect = DrawManager.MenuSelectCursor(7, 3, 8, HEIGHT*0.2);

	switch (iSelect)
	{
	case 1:
		m_iSelectWAttack = Daggers[0].GetAttack();
		m_iSelectWGold = Daggers[0].GetPrice();
		m_bFlag = true;
		b = D;
		break;
	case 2:
		m_iSelectWAttack = Daggers[1].GetAttack();
		m_iSelectWGold = Daggers[1].GetPrice();
		b = D;
		m_bFlag = true;
		break;
	case 3:
		m_iSelectWAttack = Daggers[2].GetAttack();
		m_iSelectWGold = Daggers[2].GetPrice();
		b = D;
		m_bFlag = true;
		break;
	case 4:
		m_iSelectWAttack = Daggers[3].GetAttack();
		m_iSelectWGold = Daggers[3].GetPrice();
		b = D;
		m_bFlag = true;
		break;
	case 5:
		m_iSelectWAttack = Daggers[4].GetAttack();
		m_iSelectWGold = Daggers[4].GetPrice();
		b = D;
		m_bFlag = true;
		break;
	case 6:
		m_iSelectWAttack = Daggers[5].GetAttack();
		m_iSelectWGold = Daggers[5].GetPrice();
		m_bFlag = true;
		b = D;
		break;
	case 7:
		m_bFlag = false;
		return;
	default:
		break;
	}
}
void Shop::ShowBows()
{
	int iSelect;
	int h = HEIGHT * 0.2;
	DrawManager.BoxErase(WIDTH, HEIGHT - 1);
	DrawManager.DrawMidText("Bow Shop", WIDTH, HEIGHT * 0.1);
	for (int i = 0; i < 5; i++)
	{
		Bows[i].Draw(h);
		h += 3;
	}
	DrawManager.DrawMidText("EXIT", WIDTH, HEIGHT * 0.7);
	iSelect = DrawManager.MenuSelectCursor(6, 3, 8, HEIGHT*0.2);

	switch (iSelect)
	{
	case 1:
		m_iSelectWAttack = Bows[0].GetAttack();
		m_iSelectWGold = Bows[0].GetPrice();
		b = B;
		m_bFlag = true;
		break;
	case 2:
		m_iSelectWAttack = Bows[1].GetAttack();
		m_iSelectWGold = Bows[1].GetPrice();
		b = B;
		m_bFlag = true;
		break;
	case 3:
		m_iSelectWAttack = Bows[2].GetAttack();
		m_iSelectWGold = Bows[2].GetPrice();
		b = B;
		m_bFlag = true;
		break;
	case 4:
		m_iSelectWAttack = Bows[3].GetAttack();
		m_iSelectWGold = Bows[3].GetPrice();
		b = B;
		m_bFlag = true;
		break;
	case 5:
		m_iSelectWAttack = Bows[4].GetAttack();
		m_iSelectWGold = Bows[4].GetPrice();
		b = B;
		m_bFlag = true;
		break;
	case 6:
		m_bFlag = false;
		return;
	default:
		break;
	}
}
void Shop::ShowWands()
{
	int iSelect;
	int h = HEIGHT * 0.2;
	DrawManager.BoxErase(WIDTH, HEIGHT - 1);
	DrawManager.DrawMidText("Wand Shop", WIDTH, HEIGHT * 0.1);
	for (int i = 0; i < 5; i++)
	{
		Wands[i].Draw(h);
		h += 3;
	}
	DrawManager.DrawMidText("EXIT", WIDTH, HEIGHT * 0.7);
	iSelect = DrawManager.MenuSelectCursor(6, 3, 8, HEIGHT*0.2);

	switch (iSelect)
	{
	case 1:
		m_iSelectWAttack = Wands[0].GetAttack();
		m_iSelectWGold = Wands[0].GetPrice();
		b = W;
		m_bFlag = true;
		break;
	case 2:
		m_iSelectWAttack = Wands[1].GetAttack();
		m_iSelectWGold = Wands[1].GetPrice();
		b = W;
		m_bFlag = true;
		break;
	case 3:
		m_iSelectWAttack = Wands[2].GetAttack();
		m_iSelectWGold = Wands[2].GetPrice();
		b = W;
		m_bFlag = true;
		break;
	case 4:
		m_iSelectWAttack = Wands[3].GetAttack();
		m_iSelectWGold = Wands[3].GetPrice();
		b = W;
		m_bFlag = true;
		break;
	case 5:
		m_iSelectWAttack = Wands[4].GetAttack();
		m_iSelectWGold = Wands[4].GetPrice();
		b = W;
		m_bFlag = true;
		break;
	case 6:
		m_bFlag = false;
		return;
	default:
		break;
	}
}
void Shop::ShowSwords()
{
	int iSelect;
	int h = HEIGHT * 0.2;
	DrawManager.BoxErase(WIDTH, HEIGHT - 1);
	DrawManager.DrawMidText("Sword Shop", WIDTH, HEIGHT * 0.1);
	for (int i = 0; i < 5; i++)
	{
		Swords[i].Draw(h);
		h += 3;
	}
	DrawManager.DrawMidText("EXIT", WIDTH, HEIGHT * 0.7);
	iSelect = DrawManager.MenuSelectCursor(6, 3, 8, HEIGHT*0.2);

	switch (iSelect)
	{
	case 1:
		m_iSelectWAttack = Swords[0].GetAttack();
		m_iSelectWGold = Swords[0].GetPrice();
		b = S;
		m_bFlag = true;
		break;
	case 2:
		m_iSelectWAttack = Swords[1].GetAttack();
		m_iSelectWGold = Swords[1].GetPrice();
		b = S;
		m_bFlag = true;
		break;
	case 3:
		m_iSelectWAttack = Swords[2].GetAttack();
		m_iSelectWGold = Swords[2].GetPrice();
		b = S;
		m_bFlag = true;
		break;
	case 4:
		m_iSelectWAttack = Swords[3].GetAttack();
		m_iSelectWGold = Swords[3].GetPrice();
		b = S;
		m_bFlag = true;
		break;
	case 5:
		m_iSelectWAttack = Swords[4].GetAttack();
		m_iSelectWGold = Swords[4].GetPrice();
		b = S;
		m_bFlag = true;
		break;
	case 6:
		m_bFlag = false;
		return;
	default:
		break;
	}
}
void Shop::ShowHammers()
{
	int iSelect;
	int h = HEIGHT * 0.2;
	DrawManager.BoxErase(WIDTH, HEIGHT - 1);
	DrawManager.DrawMidText("Hammer Shop", WIDTH, HEIGHT * 0.1);
	for (int i = 0; i < 5; i++)
	{
		Hammers[i].Draw(h);
		h += 3;
	}
	DrawManager.DrawMidText("EXIT", WIDTH, HEIGHT * 0.7);
	iSelect = DrawManager.MenuSelectCursor(6, 3, 8, HEIGHT*0.2);

	switch (iSelect)
	{
	case 1:
		m_iSelectWAttack = Hammers[0].GetAttack();
		m_iSelectWGold = Hammers[0].GetPrice();
		b = H;
		m_bFlag = true;
		break;
	case 2:
		m_iSelectWAttack = Hammers[1].GetAttack();
		m_iSelectWGold = Hammers[1].GetPrice();
		b = H;
		m_bFlag = true;
		break;
	case 3:
		m_iSelectWAttack = Hammers[2].GetAttack();
		m_iSelectWGold = Hammers[2].GetPrice();
		b = H;
		m_bFlag = true;
		break;
	case 4:
		m_iSelectWAttack = Hammers[3].GetAttack();
		m_iSelectWGold = Hammers[3].GetPrice();
		b = H;
		m_bFlag = true;
		break;
	case 5:
		m_iSelectWAttack = Hammers[4].GetAttack();
		m_iSelectWGold = Hammers[4].GetPrice();
		b = H;
		m_bFlag = true;
		break;
	case 6:
		m_bFlag = false;
		return;
	default:
		break;
	}
}
void Shop::ShowGuns()
{
	int iSelect;
	int h = HEIGHT * 0.2;
	DrawManager.BoxErase(WIDTH, HEIGHT - 1);
	DrawManager.DrawMidText("Hammer Shop", WIDTH, HEIGHT * 0.1);
	for (int i = 0; i < 4; i++)
	{
		Guns[i].Draw(h);
		h += 3;
	}
	DrawManager.DrawMidText("EXIT", WIDTH, HEIGHT * 0.6);
	iSelect = DrawManager.MenuSelectCursor(5, 3, 8, HEIGHT*0.2);

	switch (iSelect)
	{
	case 1:
		m_iSelectWAttack = Guns[0].GetAttack();
		m_iSelectWGold = Guns[0].GetPrice();
		b = G;
		m_bFlag = true;
		break;
	case 2:
		m_iSelectWAttack = Guns[1].GetAttack();
		m_iSelectWGold = Guns[1].GetPrice();
		b = G;
		m_bFlag = true;
		break;
	case 3:
		m_iSelectWAttack = Guns[2].GetAttack();
		m_iSelectWGold = Guns[2].GetPrice();
		b = G;
		m_bFlag = true;
		break;
	case 4:
		m_iSelectWAttack = Guns[3].GetAttack();
		m_iSelectWGold = Guns[3].GetPrice();
		b = G;
		m_bFlag = true;
		break;
	case 5:
		m_bFlag = false;
		return;
	default:
		break;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Shop::Random()
{
	if (m_bFlag == true)
	{
		switch (b)
				
		{
		case N:
			return;
		case D:
			Daggers[0].Show();
			m_iPlusAttack = Daggers[0].GetRandom();
			DrawManager.gotoxy(0,33);
			system("pause");
			break;
		case B:
			Bows[0].Show();
			m_iPlusAttack = Bows[0].GetRandom();
			DrawManager.gotoxy(0, 33);
			system("pause");
			break;
		case W:
			Wands[0].Show();
			m_iPlusAttack = Wands[0].GetRandom();
			DrawManager.gotoxy(0, 33);
			system("pause");
			break;
		case S:
			Swords[0].Show();
			m_iPlusAttack = Swords[0].GetRandom();
			DrawManager.gotoxy(0, 33);
			system("pause");
			break;
		case H:
			Hammers[0].Show();
			m_iPlusAttack = Hammers[0].GetRandom();
			DrawManager.gotoxy(0, 33);
			system("pause");
			break;
		case G:
			Guns[0].Show();
			m_iPlusAttack = Guns[0].GetRandom();
			DrawManager.gotoxy(0, 33);
			system("pause");
			break;
		}
	}
}
Shop::~Shop()
{
}
