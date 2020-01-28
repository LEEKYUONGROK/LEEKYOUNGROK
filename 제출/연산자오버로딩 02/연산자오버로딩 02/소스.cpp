#include "Time.h"

void main()
{
	int select;
	Time ov1(1, 0, 0), ov2(0, 0, 0);
	
	while (1)
	{
		system("cls");
		ov1.Print_clock();
		ov1.Print_Day();
		cout << "          1.시간 등록" << endl;
		cout << "          2.종료" << endl;
		cout << "          입력 : ";

		cin >> select;
		switch (select)
		{
		case 1:
			ov2.input_clock();
			ov1 + ov2;
			++ov1;
			break;
		case 2:
			return;
		}
	}
}