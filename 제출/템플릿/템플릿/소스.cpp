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
		cout << "1.입력 숫자 1증가 " << endl;
		cout << "2.두수 중 최소값" << endl;
		cout << "3.세수 중 최댓값" << endl;
		cout << "4.종료" << endl;
		cout << "입력 : ";

		cin >> select;
		switch (select)
		{
		case 1:
			system("cls");
			cout << "값을 입력하세요 : " << endl;
			cin >> m_inum1;
			Increase(m_inum1);
			break;
		case 2:
			system("cls");
			cout << "첫번쨰 값을 입력하세요 : " << endl;
			cin >> m_inum1;
			cout << "두번쨰 값을 입력하세요 : " << endl;
			cin >> m_inum2;
			Return_Min(m_inum1,m_inum2);
			break;
		case 3:
			system("cls");
			cout << "첫번쨰 값을 입력하세요 : " << endl;
			cin >> m_inum1;
			cout << "두번쨰 값을 입력하세요 : " << endl;
			cin >> m_inum2;
			cout << "세번쨰 값을 입력하세요 : " << endl;
			cin >> m_inum3;
			if (Return_Max<int>(m_inum1, m_inum2, m_inum3) == 0)
			{
				cout << "중복된 값이 있습니다" << endl;
				break;
			}
			cout << "최대값 : " << Return_Max<int>(m_inum1, m_inum2, m_inum3) << "입니다";
		}
		system("pause");
	}
}

template <typename SUM>
void Increase(SUM num1)
{
	num1++;
	cout << "증가된 값 : " << num1 << endl;
}

template <typename Input_Num>
void Return_Min(Input_Num num1, Input_Num num2)
{
	if (num1 > num2)
		cout << "최솟값 : " << num2 << "입니다" << endl;
	else if(num1 < num2)
		cout << "최솟값 : " << num1 << "입니다"<< endl;
	else 
		cout <<"둘의 수가 같습니다" << endl;
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


