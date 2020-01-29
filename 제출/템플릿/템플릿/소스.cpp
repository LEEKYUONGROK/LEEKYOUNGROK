#include <iostream>
using namespace std;

template <typename SUM>
void Increase(SUM num1);

template <typename Input_Num>
void Return_Min(Input_Num num1, Input_Num num2);

template <typename Max, typename Input_Num>
Max Return_Max(Input_Num num1, Input_Num num2, Input_Num num3);

void main()
{
	int select, m_inum1, m_inum2, m_inum3;
	while (1)
	{
		system("cls");
		cout << "1.�Է� ���� 1���� " << endl;
		cout << "2.�μ� �� �ּҰ�" << endl;
		cout << "3.���� �� �ִ�" << endl;
		cout << "4.����" << endl;
		cout << "�Է� : ";

		cin >> select;
		switch (select)
		{
		case 1:
			system("cls");
			cout << "���� �Է��ϼ��� : " << endl;
			cin >> m_inum1;
			Increase(m_inum1);
			break;
		case 2:
			system("cls");
			cout << "ù���� ���� �Է��ϼ��� : " << endl;
			cin >> m_inum1;
			cout << "�ι��� ���� �Է��ϼ��� : " << endl;
			cin >> m_inum2;
			Return_Min(m_inum1,m_inum2);
			break;
		case 3:
			system("cls");
			cout << "ù���� ���� �Է��ϼ��� : " << endl;
			cin >> m_inum1;
			cout << "�ι��� ���� �Է��ϼ��� : " << endl;
			cin >> m_inum2;
			cout << "������ ���� �Է��ϼ��� : " << endl;
			cin >> m_inum3;
			if (Return_Max<int>(m_inum1, m_inum2, m_inum3) == 0)
			{
				cout << "�ߺ��� ���� �ֽ��ϴ�" << endl;
				break;
			}
			cout << "�ִ밪 : " << Return_Max<int>(m_inum1, m_inum2, m_inum3) << "�Դϴ�";
		}
		system("pause");
	}
}

template <typename SUM>
void Increase(SUM num1)
{
	num1++;
	cout << "������ �� : " << num1 << endl;
}

template <typename Input_Num>
void Return_Min(Input_Num num1, Input_Num num2)
{
	if (num1 > num2)
		cout << "�ּڰ� : " << num2 << "�Դϴ�" << endl;
	else if(num1 < num2)
		cout << "�ּڰ� : " << num1 << "�Դϴ�"<< endl;
	else 
		cout <<"���� ���� �����ϴ�" << endl;
}

template <typename Max,typename Input_num>
Max Return_Max(Input_num num1, Input_num num2, Input_num num3)
{
	Max max_num;
	if (num1 > num2 && num1 > num3)
	{
		max_num = num1;
		return max_num;
	}
	else if (num2 > num1 && num2 > num3)
	{
		max_num = num2;
		return max_num;
	}
	else if (num3 > num2 && num3 >> num1)
	{
		max_num = num3;
		return max_num;
	}
	else
		return 0;
}


