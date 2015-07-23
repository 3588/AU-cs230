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
	poly();	//��ʼ��
	~poly();
	void creat(vector <int>,vector <int>); //��ȡ����
	void evaluate(const poly& p, double x);	//���м���
	//friend poly operator +(const poly& p1,const poly& p2);
	//friend poly operator -(const poly& p1,const poly& p2);
	friend poly operator *(const poly& p1,const poly& p2);
	poly& operator =(const poly& p);
	friend ostream& operator <<(ostream& outs,const poly& p);
	intptr polyomial;
	int len;
};
#endif
