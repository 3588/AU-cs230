#include"Plane.h"

Plane::Plane(int flt,int time,Plane_status status)
{
	flt_num=flt;
	clock_start=time;
	state=status;
	cout<<"Plane number "<<flt<<" ready to "<<((status==arriving)?"land.":"take off.")<<endl;
}

Plane::Plane()
{
	flt_num=-1;
	clock_start=-1;
	state=null;
}

void Plane::refuse()const
{
	cout<<"Plane number "<<flt_num
		<<((state==arriving)?" directed to another airport.":" told to try to takeoff again later.")<<endl;
}

void Plane::land(int time)const
{
	int wait=time-clock_start;
	cout<<time<<":Plane number "<<flt_num<<" landed after "
		<<wait<<" time unit"<<((wait==1)?"":"s")<<" in the takeoff queue."<<endl;
}

void Plane::fly(int time)const
{
	int wait=time-clock_start;
	cout<<time<<":Plane number "<<flt_num<<" took off after "
		<<wait<<" time unit"<<((wait==1)?"":"s")<<" in the takeoff queue."<<endl;
}

int Plane::started()const
{
	return clock_start;
}

