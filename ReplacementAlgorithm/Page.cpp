#include "stdafx.h"
#include "Page.h"


Page::Page()
{
	this->num = -1;
	this->time = 0;
}

int Page::getNum(){
	return this->num;
}
int Page::getTime(){
	return this->time;
}
void Page::setNum(int num){
	this->num = num;
}
void Page::setTime(int time){
	this->time = time;
}

Page::~Page()
{
}
