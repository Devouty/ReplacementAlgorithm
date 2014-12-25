#include "stdafx.h"
#include "RandomNumber.h"
#include <cstdlib>
RandomNumber::RandomNumber()
{
}

int RandomNumber::getNum(int i){
	return num[i];
}
void RandomNumber::random(){
	int i = 0;
	while (i<200)
	{
		num[i] = rand() % 200;
		num[i+1] = num[i] + 1;
		num[i + 200] = rand() % 200 + 200;
		num[i + 201] = num[i + 200] + 1;
		i++;
	}
}
int * RandomNumber::getList()
{
	return num;
}
RandomNumber::~RandomNumber()
{
}
