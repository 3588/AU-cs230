#include<iostream>
#include "assignment1.h"
using namespace std;

void Get_Data(int &hw,int &sw,int &sl)//get Data
{
	int t[4];
	do 
	{
		t[0]=1;//check
		cout<<"Enter head width : ";
		cin>>t[1];
		cout<<"Enter shaft length : ";
		cin>>t[2];
		cout<<"Enter shaft width : ";
		cin>>t[3];
		cout<<"Your enter head width is : "<<t[1]<<" shaft length is : "<<t[2]<<" shaft width is : "<<t[3]<<endl;
		char t_y_n='n';
		cout<<"Your enter is right?(y or n)";
		cin>>t_y_n;
		if (t_y_n=='y'||t_y_n=='Y')
		{
			hw=t[1];
			sl=t[2];
			sw=t[3];
			//start check user enter
			Check_Hw(hw);
			Check_Hw_Sw(hw,sw);
			Check_Sl_Sw(sl,sw);
			if (hw!=0&&sw!=0&&sl!=0)
			{
				t[0]=0;//correct data
			}
			else//delete data
			{
				hw=0;
				sw=0;
				sl=0;
			}
		}
		else
		{
			cout<<"Enter data again\n";
		}
	} while (t[0]);

	if (hw%2==0)
	{
		Get_Positive_Odd_Int(hw);
	}
	if (sw%2==0)
	{
		Get_Positive_Odd_Int(sw);
	}
	if (sl%2==0)
	{
		Get_Positive_Odd_Int(sl);
	}
}
void Up_Down_Left_Right(int &U_D_L_R) //1.The direction of the arrow is selected by clicking a radio button. So, there has to be four radio buttons, one for each direction.
{
	Word(6);
	int check=0;
	do 
	{
		cin>>U_D_L_R;
		for (int i=0;i<6;i++)
		{
			if (U_D_L_R==i)
			{
				check=0;
				break;
			}
			else
			{check=1;}
		}
	} while (check);



	if (U_D_L_R==0)
	{
		Check_Close(U_D_L_R);
	}
}
//2.The default direction is up. So, your application should make that selection once started.
void Get_Positive_Odd_Int(int &even_odd)//3.The head width, shaft length, and shaft width are all positive odd integers. If an even number is specified, the next smaller odd number is used.
{
	even_odd=even_odd-1;
	//test error
	if (even_odd%2==0)
	{
		cout<<"error 1";
		exit(1);
	}
}
void Check_Hw(int &hw)//4.The head width must be greater than or equal to 5 and less than or equal to 25.
{
	if (hw<5||hw>25)//error hw
	{
		hw=0;
		Word(3);
	} 
}
void Check_Hw_Sw(int &hw, int &sw)//5. The width of the head is longer than the width of the shaft.
{
	if (hw==0)//error hw
	{
		sw=0;
	}
	else
	{
		if (hw<=sw)//error sw or hw
		{
			hw=0;
			sw=0;
			Word(4);
		}

	}

}
void Check_Sl_Sw(int &sl, int&sw)//6.The length of the shaft is at least as long as the width of the shaft.
{
	if (sw==0)//error sw
	{
		sl=0;
	}
	else
	{
		if (sl<sw)//error sl or sw
		{
			sl=0;
			sw=0;
			Word(5);
		}

	}
}
void Check_Close(int &tem)//7. She does not want to exit the application by accident. So, she wants the application to verify with her as it is closing
{
	if (tem==0)
	{
		Word(7);
		char yn;
		cin>>yn;
		if (yn=='y'||yn=='Y')
		{
			Word(8);
			exit(1);
		} 
		else
		{
			tem=1;
		}
	}
}
void Output(int hw,int sw,int sl, int u_d_l_r)  
{
	if (u_d_l_r==1)//up
	{
		int stars = 1, spaces = hw/2, maxLines = (hw+1)/2;
		for(int i =1 ; i <= maxLines; i++)
		{
			for(int j = 1 ; j <= spaces ; j++)
			{cout<<" ";}
			for(int l = 1 ; l <= stars ; l++)
			{cout<<"*";}
			spaces --;
			stars +=2;
			cout<<endl;
		}
		shaft(0,hw,sw,sl);//0.up and down 
	}
	if (u_d_l_r==2)//down
	{
		shaft(0,hw,sw,sl);//0.up and down 
		int stars = hw, spaces = 0, maxLines = (hw+1)/2;
		for(int i =1 ; i <= maxLines; i++)
		{
			for(int j = 0 ; j < spaces ; j++)
			{cout<<" ";}
			for(int l = 1 ; l <= stars ; l++)
			{cout<<"*";}
			spaces ++;
			stars -=2;
			cout<<endl;
		}
	}
	if (u_d_l_r==3)//left
	{
		int spaces=hw/2, High=(hw+1)/2;
		for (int i=1;i<=hw;i++)
		{
			if (i<=hw/2)
			{	
				for (int j=0;j<spaces;j++)
				{cout<<" ";}
				for (int l=0;l<High-spaces;l++ )
				{cout<<"*";}
				spaces--;

			}
			else
			{
				for (int j=0;j<spaces;j++)
				{cout<<" ";}
				for (int l=0;l<High-spaces;l++ )
				{cout<<"*";}
				spaces++;

			}
			shaft(i,hw,sw,sl);

		}
	}

	if (u_d_l_r==4)//right
	{
		int spaces=hw/2, High=(hw+1)/2;
		int thw=hw+100;//temporary display right
		for (int i=1;i<=hw;i++)
		{
			shaft(i,thw,sw,sl);
			if (i<=hw/2)
			{	
				for (int l=0;l<High-spaces;l++ )
				{cout<<"*";}
				for (int j=0;j<spaces;j++)
				{cout<<" ";}
				spaces--;
				cout<<endl;
			}
			else
			{				
				for (int l=0;l<High-spaces;l++ )
				{cout<<"*";}
				for (int j=0;j<spaces;j++)
				{cout<<" ";}
				spaces++;
				cout<<endl;
			}

		}
	}
}
void shaft(int t, int hw, int sw, int sl)//0.up and down 
{
	if (t==0)
	{
		int spaces = (hw-sw)/2;
		for (int i = 0; i<sl;i++)
		{
			for(int j = 0 ; j < spaces ; j++)
			{cout<<" ";}
			for(int l = 0 ; l < sw ; l++)
			{cout<<"*";}
			cout<<endl;
		}
	}
	if (t!=0)//t=line
	{
		int l_hw=hw;
		if (hw>=100)//right
		{
			hw-=100;
		}

		int high=hw-sw;
		for (int i = 0; i<sl; i++)
		{
			if (t>high/2&&t<=sw+high/2)
			{cout<<"*";} 
			else
			{cout<<" ";}
		}
		if (l_hw<100)
		{cout<<endl;}

	}

}
void Word(int tem)//display word
{
	if(tem==1)
	{cout<<"Welcome Play Drawing Arrows\n\n"<<"The game rules\n";}
	if (tem==2)
	{cout<<"1.The head width, shaft length, and shaft width are all positive odd integers. If an even number is specified, the next smaller odd number is used.\n";}
	if (tem==3)
	{cout<<"2.The head width must be greater than or equal to 5 and less than or equal to 25.\n";}
	if (tem==4)
	{cout<<"3.The width of the head is longer than the width of the shaft.\n";}
	if (tem==5)
	{cout<<"4.The length of the shaft is at least as long as the width of the shaft.\n";}
	if (tem==6)
	{cout<<"\n1.up  2.down  3.left   4.right   5.Input new data  0.exit (Enter number only!!!)\nEnter your choose : ";}
	if (tem==7)
	{cout<<"\n*******************\nDo you want exit?(y/n)\n*******************\n";}
	if(tem==8)
	{cout<<"\nBye Bye!!\n";}
}