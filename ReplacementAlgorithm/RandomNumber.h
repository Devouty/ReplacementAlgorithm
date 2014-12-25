/*
this class make the software get a new random list easier
*/
#pragma once
class RandomNumber
{
public:
	RandomNumber();
	~RandomNumber();
	int getNum(int i);
	void random();
	int * getList();
private:
	int num[400];
};

