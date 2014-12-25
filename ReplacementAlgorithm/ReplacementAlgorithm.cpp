// ReplacementAlgorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "RandomNumber.h"
#include "Page.h"
#include "Calculator.h"
#include <string>
#include <iostream>
using namespace::std;
int _tmain(int argc, _TCHAR* argv[])
{
	
	//new a RandomNumber class
	RandomNumber rn;
	rn.random();
	
	//get address list
	int * num = rn.getList();

	//set page 0~9 is page 0,10~19is page 1,etc.
	Page page[400];
	for (int i = 0; i < 400; i++)
		page[i].setNum(num[i] / 10);

	//calculatir for algorithm
	Calculator calculatir;

	//main loop
	while (true)
	{
		//view
		system("cls");
		cout<< "                     ************************************" << endl;
		cout<< "                     *ҳ���û��㷨��ģ��ʵ�ּ������ʶԱ�*" << endl;
		cout<< "                     ************************************" << endl;
		cout<< "������1���鿴��ǰ��ַ���У���Ŀ�Ӵ���ѡ��" << endl
			<< "      2���鿴��ǰ��ַ���ж�Ӧ��ҳ����Ŀ�Ӵ���ѡ��" << endl
			<< "      3�����´�����ַ��" << endl
			<< "      4������ÿ���ڴ������²�ͬҳ���û��㷨��������" << endl
			<< "      0���˳�" << endl
			<< "�����룺";
		
		//get input choose
		string choose;
		cin >> choose;

		//action for choose
		switch (choose[0])
		{
		case 1 + '0'://�鿴��ǰ��ַ���У���Ŀ�Ӵ���ѡ��
			cout << "��ǰ��ַ����Ϊ��" << endl;
			for (int j = 0; j < 400; j++)
				cout << num[j] << " ";
			cout << endl;
			system("pause");
			break;

		case 2 + '0'://�鿴��ǰ��ַ���ж�Ӧ��ҳ
			cout << "��ǰҳ����Ϊ��" << endl;
			for (int j = 0; j < 400; j++)
				cout << page[j].getNum() << " ";
			cout << endl;
			system("pause");
			break;

		case 3 + '0'://���´�����ַ��
			//random again
			rn.random();

			//get address list
			num = rn.getList();

			//set page 0~9 is page 0,10~19 is page 1,etc.
			for (int i = 0; i < 400; i++)
				page[i].setNum(num[i] / 10);
			cout << "���´����ɹ���" << endl;
			system("pause");
			break;

		case 4 + '0'://����ÿ���ڴ������²�ͬҳ���û��㷨��������
			cout << "ҳ����  OPTȱҳ��      FIFOȱҳ��      LRUȱҳ��" << endl;
			cout.setf(ios::showpoint);
			cout.precision(4);
			
			for (int frame = 4; frame <= 40; frame++)
			{
				printf(" [%2d]   OPT:%6.4f     FIFO:%6.4f     LRU:%6.4f\n", 
					frame, 
					calculatir.OPT(frame, page), 
					calculatir.FIFO(frame, page), 
					calculatir.LRU(frame, page));
			}
			system("pause");
			break;

		case 0 + '0'://�˳�
			exit(0);

		default://error input
			break;
		}
	}



	return 0;
}

