#pragma once
class Page
{
public:
	Page();
	int getNum();
	int getTime();
	void setNum(int num);
	void setTime(int time);
	~Page();
private:
	int num;
	int time;
};

