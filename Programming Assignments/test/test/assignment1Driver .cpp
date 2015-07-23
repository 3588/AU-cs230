#include<iostream>
#include "assignment1.h"

using namespace std;

int main()
{
	int OneMore=0,U_D_L_R=0;
	int hw=0,sw=0,sl=0;
	do 
	{
		if (OneMore==0)
		{
			for (int i=1;i<6;i++)
			{Word(i);}
			U_D_L_R=5;
		}
					
			if (U_D_L_R==5)//get new data or first time
			{				
				Get_Data(hw,sw,sl);
			}	
		if (OneMore==0)//first time
		{
			U_D_L_R=1;//up
			Output(hw,sw,sl,U_D_L_R);//first time up
			
		}		
		Up_Down_Left_Right(U_D_L_R);//ask up or down or l or r
		if (U_D_L_R!=5)//user don't need new data 
		{
			Output(hw,sw,sl,U_D_L_R);			
		}
		OneMore++;
		//cout<<"\nYour Play "<<OneMore+1<<" times\n";

	} while (OneMore);
	return 0;
}