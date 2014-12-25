// ReplacementAlgorithm.cpp : 定义控制台应用程序的入口点。
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
		cout<< "                     *页面置换算法的模拟实现及命中率对比*" << endl;
		cout<< "                     ************************************" << endl;
		cout<< "操作：1：查看当前地址队列（数目庞大，慎选）" << endl
			<< "      2：查看当前地址队列对应的页（数目庞大，慎选）" << endl
			<< "      3：重新创建地址流" << endl
			<< "      4：计算每个内存容量下不同页面置换算法的命中率" << endl
			<< "      0：退出" << endl
			<< "请输入：";
		
		//get input choose
		string choose;
		cin >> choose;

		//action for choose
		switch (choose[0])
		{
		case 1 + '0'://查看当前地址队列（数目庞大，慎选）
			cout << "当前地址序列为：" << endl;
			for (int j = 0; j < 400; j++)
				cout << num[j] << " ";
			cout << endl;
			system("pause");
			break;

		case 2 + '0'://查看当前地址队列对应的页
			cout << "当前页序列为：" << endl;
			for (int j = 0; j < 400; j++)
				cout << page[j].getNum() << " ";
			cout << endl;
			system("pause");
			break;

		case 3 + '0'://重新创建地址流
			//random again
			rn.random();

			//get address list
			num = rn.getList();

			//set page 0~9 is page 0,10~19 is page 1,etc.
			for (int i = 0; i < 400; i++)
				page[i].setNum(num[i] / 10);
			cout << "重新创建成功！" << endl;
			system("pause");
			break;

		case 4 + '0'://计算每个内存容量下不同页面置换算法的命中率
			cout << "页框数  OPT缺页率      FIFO缺页率      LRU缺页率" << endl;
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

		case 0 + '0'://退出
			exit(0);

		default://error input
			break;
		}
	}



	return 0;
}

