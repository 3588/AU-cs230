#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <cstdlib>
#include <cstddef> 
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;
typedef int* intptr;
class poly
{
public:
	poly();	//初始化
	~poly();
	void creat(vector <int>,vector <int>); //获取数据
	void evaluate(const poly& p, double x);	//进行计算
	//friend poly operator +(const poly& p1,const poly& p2);
	//friend poly operator -(const poly& p1,const poly& p2);
	friend poly operator *(const poly& p1,const poly& p2);
	poly& operator =(const poly& p);
	friend ostream& operator <<(ostream& outs,const poly& p);
	intptr polyomial;
	int len;
};
#endif
