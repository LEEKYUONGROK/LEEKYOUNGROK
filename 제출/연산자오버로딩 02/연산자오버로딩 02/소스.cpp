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
		cout << "          1.�ð� ���" << endl;
		cout << "          2.����" << endl;
		cout << "          �Է� : ";

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