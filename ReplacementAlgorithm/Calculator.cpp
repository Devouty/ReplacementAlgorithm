#include "stdafx.h"
#include "Calculator.h"


Calculator::Calculator()
{
}
int Calculator::contains(Page *page, int e)//find & return the flag(-1) or location(i)
{							   //if page list has such number(e)
	Page *p = new Page[400];
	p = page;
	for (int i = 0; i<400; i++)
	if (e == p[i].getNum())
		return i;
	return -1;
}
int Calculator::replace(Page *p, int e)//replace page into frame,					   
{						   //return the replacement location
	int i, loc = 0, maxtime = -1;
	for (i = 0; i<e; i++)
	{
		if (p[i].getTime() >= maxtime)
		{
			maxtime = p[i].getTime();
			loc = i;
		}
	}
	return loc;
}
double Calculator::OPT(int frame, Page * page){
	Page * opt = new Page[400];
	double missOfFrame = 0;
	int temp = 0;//frameNum
	for (int i = 0; i < 400; i++)
	{
		int num = contains(opt, page[i].getNum());
		if (num == -1)//didn't contains		
		{
			missOfFrame++;

			if (opt[frame - 1].getNum() == -1)//if some frame is blank
						opt[temp++].setNum(page[i].getNum());
			else//no blank
			{
				for (int k = 0; k < frame; k++)
				{
					for (int j = i; j < 400; j++)
					{
						if (opt[k].getNum() == page[j].getNum())
						{
							opt[k].setTime(j);
							break;
						}
						else
							opt[k].setTime(401);//set time to a max number
					}
				}
				//replace() return the location,then set number for opt[] by location
				opt[replace(opt,frame)].setNum(page[i].getNum());
			}
		}
		
	}
	return (1 - ((missOfFrame - frame) / 400));
	//if missOfFrame == frame ,return 1.
}
double Calculator::FIFO(int frame, Page *page){
	Page * fifo = new Page[400];
	double missOfFrame = 0;
	int temp = 0;//frameNum
	for (int i = 0; i < 400;)
	{
		if (contains(fifo, page[i].getNum()) != -1)//didn't contains
			i++;//then add it into frame
		else//frame is full
		{
			missOfFrame++;
			temp = temp%frame;//根据fifo性质，可以由此标记要替换的位置
			fifo[temp++].setNum(page[i].getNum());
		}
	}
	return (1 - (missOfFrame - frame) / 400);
	//if missOfFrame == frame ,return 1.
}
double Calculator::LRU(int frame, Page *page){
	Page * lru = new Page[400];
	double missOfFrame = 0;
	bool flag;//flag if the page is in memory

	for (int i = 0; i < 400; i++)
	{
		flag = false;
		for (int f = 0; f < frame; f++)
		{//find if the page is in the frame list
			//if found ,set flag&time = 0, break this loop
			if (page[i].getNum() == lru[f].getNum())
			{
				lru[f].setTime(0);
				flag = true;
				break;
			}
		}
		if (flag == false)
		{//page is not in frame
			missOfFrame++;

			if (lru[frame - 1].getNum() != -1)
			{//frame is full
				int loc = 0;
				int maxTime = lru[0].getTime();
				for (int t = 0; t<frame; t++)
				{//get the page's location which time is max
					if (lru[t].getTime()>maxTime)
					{
						maxTime = lru[t].getTime();
						loc = t;
					}
				}
				lru[loc].setNum(page[i].getNum());
				lru[loc].setTime(0);
			}
			else//frame still has space
			{//take the page[i] into frame
				for (int j = 0; j < frame; j++)
				{
					if (lru[j].getNum() == -1)
					{
						lru[j].setNum(page[i].getNum());
						break;
					}
				}
			}
		}

		for (int j = 0; j < frame; j++)
		{//page in the frame,its time should ++
			if (lru[j].getNum() != -1)
				lru[j].setTime(lru[j].getTime() + 1);
		}
	}

	return (1 - (missOfFrame - frame) / 400);
	//if missOfFrame == frame ,return 1.
}

Calculator::~Calculator()
{
}
