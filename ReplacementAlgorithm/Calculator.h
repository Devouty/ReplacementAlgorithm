/*
the Calculator class for replacement algorithm,include OPT,FIFO,LRU
*/
#pragma once
#include "Page.h"
class Calculator
{
public:
	Calculator();
	double OPT(int frame, Page *page);
	double FIFO(int frame, Page *page);
	double LRU(int frame, Page *page);
	~Calculator();
private:
	int contains(Page *page, int e);
	int replace(Page *p, int e);
};

