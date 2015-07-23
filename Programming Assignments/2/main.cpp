#include <iostream>
#include"rectangle.h"

using namespace std;


bool Rectangle::CheckInput()
{
	//x1y1  x2y2
	//
	//x3y3 x4y4
	if (x1==x3&&y1==y2&&x2==x4&&y3==y4)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void Rectangle::GetData()
{
	cout<<"x1 : "<<x1<<" y1 : "<<y1<<" x2 : "<<x2<<" y2 : "<<y2<<" x3 : "<<x3<<" y3 : "<<y3<<" x4 : "<<x4<<" y4 : "<<y4<<endl;
}
void Rectangle::SetData(int gx1,int gy1, int gx2, int gy2, int gx3, int gy3,int gx4, int gy4)
{
	x1=gx1;
	y1=gy1;
	x2=gx2;
	y2=gy2;
	x3=gx3;
	y3=gy3;
	x4=gx4;
	y4=gy4;
}
bool Rectangle::Getlarger()
{
	if (y1-y3>x2-x1)
	{
		return true;
	} 
	else
	{
		return false;//square or vertical
	}
}
void Rectangle::GetDataLength(char c)
{
	cout<<"Length is:";
	if (c=='c')
	{
		cout<<y1-y3<<endl;
	} 
	if(c=='v')
	{
		cout<<x2-x1<<endl;
	}
}
void Rectangle::GetDataWidth(char c)
{
	cout<<"Width is:";
		if (c=='c')
		{
			cout<<x2-x1<<endl;
		} 
		if(c=='v')
		{
			cout<<y1-y3<<endl;
		}
}
void Rectangle::GetDataPerimeter()
{
	cout<<"Perimeter is: "<<2*(x2-x1)+2*(y1-y3)<<endl;
}
void Rectangle::GetDataArea()
{
	cout<<"Area is: "<<(x2-x1)*(y1-y3)<<endl;
}
bool Rectangle::IfDataSquare()
{
    if((x2-x1)==(y1-y3))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Rectangle::GetDataDraw(char type)
{
    if(type=='f')
    {
        for(int i=0;i<y1-y3;i++)
        { 
            for(int j=0;j<x2-x1;j++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
    }
    if(type=='p')
    {
         for(int i=0;i<y1-y3;i++)
        { 
            if(i==0||i==y1-y3-1)
            {
                for(int t=0;t<x2-x1;t++)
                    cout<<"* ";
            }
            else
            {
                cout<<"* ";
                for(int j=0;j<x2-x1-2;j++)
            {
                cout<<"  ";
            }
                cout<<"*";
            }
            
            cout<<endl;
        }
    }
}
void UserMenu(int &t)
{
    int choose;
    do{
    cout<<"User Menu\n1.Length\n2.Width,\n3,Perimeter\n4.Area\n5.Square\n6.Fill-character\n7.Perimeter-character\n8.Exit\n";
    cin>>choose;
    if(choose<1||choose>8)
        choose=0;
    }while(choose==0);
    t=choose;
}
bool check(int t)
{
    if(t<21&&t>0)
        return false;
    else
        return true;
}
void Input(Rectangle &r1)
{
    int x[4],y[4],onemore=0;
    char tt;
    do{
       onemore=0;
    cout<<"Enter four pairs of numbers. EX:x,y\n";
    for(int i=0;i<4;i++)
    { 
        cin>>x[i]>>tt>>y[i];
    }
     for(int i=0;i<4;i++)
    { 
         if(check(x[i])||check(y[i]))
         {
          cout<<"Enter wrong: "<<i<<endl;
         onemore=1;
         }
    }
    r1.SetData(x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]);
    r1.GetData();
    if(r1.CheckInput())
    {
        cout<<"Your enter not a rectangle\n";
        onemore=1;
    }
    }while(onemore);
}            

int main()
{
    
	Rectangle r1;
	//r1.SetData(2,10,9,10,2,3,9,3);
        r1.SetData(2,10,15,10,2,3,15,3);
	r1.GetData();
	if (r1.Getlarger())
	{
		r1.GetDataLength('c');//crosswise
		r1.GetDataWidth('c');//crosswise
	} 
	else
	{
		r1.GetDataLength('v');//vertical
		r1.GetDataWidth('v');//vertical
	}
	r1.GetDataPerimeter();
	r1.GetDataArea();
        if(r1.IfDataSquare())
        {cout<<"it is a square\n";}
        r1.GetDataDraw('f');
        
        
        //main
        Input(r1);
        int choose=0,onemore=1;
        do{
        UserMenu(choose);
        if(choose==1)
        {
            if (r1.Getlarger())
	{
		r1.GetDataLength('c');//crosswise
	} 
	else
	{
		r1.GetDataLength('v');//vertical
	}
        }
        if(choose==2)
        {
            if (r1.Getlarger())
	{
		r1.GetDataWidth('c');//crosswise
	} 
	else
	{
		r1.GetDataWidth('v');//vertical
	}
        }
        if(choose==3)
        {
            r1.GetDataPerimeter();
        }
        if(choose==4)
        {
            r1.GetDataArea();
        }
        if(choose==5)
        {
            if(r1.IfDataSquare())
                {cout<<"it is a square\n";}
            else
                {cout<<"it isn't a square\n";}
        }
        if(choose==6)
        {r1.GetDataDraw('f');}
        if(choose==7)
        {r1.GetDataDraw('p');}
        if(choose==8)
        {onemore=0;}
        }while(onemore);
	return 0;
}