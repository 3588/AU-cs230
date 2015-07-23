#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"

using namespace std;
void Get_input(ifstream& in,LinkedList<string> &,	LinkedList<string> &,	LinkedList<string> &);//get input from file
void insertTable(string ,string ,string ,LinkedList<string> &,	LinkedList<string> &,	LinkedList<string> &);//insert data
void Get_location_byname(int&,string,LinkedList<string>);
void viewbyname(LinkedList<string>,LinkedList<string>);
void delbyname(LinkedList<string>&,LinkedList<string>&,LinkedList<string>&);
void modifybyname(LinkedList<string>&,LinkedList<string>&,LinkedList<string>&);
void savefile(LinkedList<string>);
void retrieve_zipcode(LinkedList<string>&,LinkedList<string>&);
void menu();
int main()
{
	//3 table  same location(id)
	//table1=name
	//table2=data
	//table3=zip code
	//
	//put table 1,2,3  together
	//use table1 to find id. view,delete,modify
	//use table3 to retrieve zip code
	//
	LinkedList<string> table1,table2,table3;
while (1)
{
	int choose=0;
	menu();
	cin>>choose;
	cin.ignore(1000,'\n');
	if (choose==8)
		exit(1);
	ifstream in;
	in.open("input.txt");

	switch (choose)
	{
	case 1:
		Get_input(in,table1,table2,table3);//get data from file, then insert to table1,2,3.
		table2.printList();//test
		break;
	case 2:
		viewbyname(table1,table2);
		Get_input(in,table1,table2,table3);//get data from file, then insert to table1,2,3.
		break;
	case 3:
		delbyname(table1,table2,table3); 
		break;
	case 4:
		modifybyname(table1,table2,table3);
		break;
	case 5:
			savefile(table2);
			Get_input(in,table1,table2,table3);//get data from file, then insert to table1,2,3.
			break;
	case 6:
			retrieve_zipcode(table2,table3);
			Get_input(in,table1,table2,table3);//get data from file, then insert to table1,2,3.
			break;
	case 7:
			table2.printList();
			break;
	default:
		break;
	}
	

	/*
	if (choose==1)
	{
	
		Get_input(in,table1,table2,table3);//get data from file, then insert to table1,2,3.
		table2.printList();//test
		in.close();
	}
	if (choose==2)
	{
		viewbyname(table1,table2);
		ifstream in;
		in.open("input.txt");
		Get_input(in,table1,table2,table3);//get data from file, then insert to table1,2,3.
		in.close();
	}
	if (choose==3)
	{
			delbyname(table1,table2,table3); 
	}

	if (choose==4)
	modifybyname(table1,table2,table3);
	if (choose==5)
	savefile(table2);
	if (choose==6)
	retrieve_zipcode(table2,table3);
	if (choose==7)
	table2.printList();
	*/
}

return 0;
}
void Get_input(ifstream &in,LinkedList<string> &table1,	LinkedList<string> &table2,	LinkedList<string> &table3)
{

	if (in.fail())
		cout<<"no file\n";
	else//open
	{
		table1.resetList();
		table2.resetList();
		table3.resetList();
		while (!in.eof())
		{
			string name,address1,address2,country,phone,data,zipcode="";
			getline(in,name);
			getline(in,address1);
			getline(in,address2);
			getline(in,country);
			getline(in,phone);
			getline(in,data);//get blank
			int l=address2.length();
			for (int i=0;i<l;i++)
			{
				//ascii  48 =>0  57=>9
				//get zipcode
				if (address2.at(i) > 47 && address2.at(i) < 58)
					zipcode+=address2.at(i);//add number
			}
			data=name+"\n"+address1+"\n"+address2+"\n"+country+"\n"+phone+"\n";//add data
			insertTable(name,data,zipcode,table1,table2,table3);

		}
	}
	in.close();
}

void insertTable(string name,string data,string zipcode,LinkedList<string> &table1,	LinkedList<string> &table2,	LinkedList<string> &table3)
	{
		//table1=name
		//table2=address
		//table3=zip code

		table1.insertAtBack(name);
		table2.insertAtBack(data);
		table3.insertAtBack(zipcode);
	}
void Get_location_byname(int &y,string x,LinkedList<string> table1)
{

	int t=table1.getListLength()+1;
	string str;
	for (int i=1;i<t;i++)
	{
		table1.printatlocation(i,str);
		if (str==x)
		{
			y=i;
			break;
		}
		else
		{
	y=0;

		}
	}
}
void viewbyname(LinkedList<string> table1,LinkedList<string> table2)
{
	cout<<"Enter name(ex:Junjun Huang):\n";
	string str1,str2,str3;
	getline(cin,str1);
	int t=table1.getListLength();
	for (int i=1;i<t+1;i++)
	{
		table1.printatlocation(i,str2);
		if (str2==str1)
		{
			table2.printatlocation(i,str3);
			cout<<"\n"<<str3<<"\n";
		}
		else
		{

		}
	}
	return ;
}
void delbyname(LinkedList<string> &table1,LinkedList<string> &table2,LinkedList<string> &table3)
{
	int total=table1.getListLength();
	cout<<"Enter name(ex:Junjun Huang):\n";
	string str;
	getline(cin,str);
	int x,tx;
	Get_location_byname(x,str,table1);
	if (x==0)
	{
		return;
	}
	cout<<"x"<<x<<" total:"<<total;
	ofstream fout;
	fout.open("input.txt");
	fout.close();
	fout.open("input.txt",ios::app);
	tx=x;
	for (int i=1;i<tx;i++)
	{
		table2.printatlocation(i,str);
		fout<<str<<"\n";
	}
	//fout<<data;
	for (int i=tx+1;i<total+1;i++)
	{

		table2.printatlocation(i,str);
		fout<<str<<"\n";
	}
	fout.close();
	ifstream in;
	in.open("input.txt");
	table1.resetList();
	table2.resetList();
	table3.resetList();
	Get_input(in,table1,table2,table3);//get data from file, then insert to table1,2,3.
	in.close();
	return;
}
void modifybyname(LinkedList<string>& table1,LinkedList<string>& table2,LinkedList<string> &table3)
{
	int total=table2.getListLength();
	cout<<"Enter name(ex:Junjun Huang):\n";
	string str;
	getline(cin,str);
	int x,tx;
	Get_location_byname(x,str,table1);
	if (x==0)
	{
		return;
	}
	cout<<"\nModify Address Record\n";
	string name,address1,address2,country,phone,data;
	cout<<"Name: ";
	getline(cin,name);
	cout<<"Street Address: ";
	getline(cin,address1);
	cout<<"City, State Zip: ";
	getline(cin,address2);
	cout<<"Country: ";
	getline(cin,country);
	cout<<"Phone: ";
	getline(cin,phone);

	data=name+"\n"+address1+"\n"+address2+"\n"+country+"\n"+phone;//add data

	

	ofstream fout;
	fout.open("input.txt");
	fout.close();
	fout.open("input.txt",ios::app);
	tx=x;
	for (int i=1;i<tx;i++)
	{
		table2.printatlocation(i,str);
		fout<<str<<"\n";
	}
	fout<<data;
	for (int i=tx+1;i<total+1;i++)
	{

		table2.printatlocation(i,str);
		fout<<str<<"\n";
	}
	fout.close();
	ifstream in;
	in.open("input.txt");
	table1.resetList();
	table2.resetList();
	table3.resetList();
	Get_input(in,table1,table2,table3);//get data from file, then insert to table1,2,3.
	return;
}
void savefile(LinkedList<string> table2)
{
	cout<<"Address Save to address.txt\n";
	ofstream fout;
	fout.open("address.txt");
	fout.close();
	fout.open("address.txt",ios::app);
	int t=table2.getListLength()+1;
	string str;
	for (int i=1;i<t;i++)
	{
		table2.printatlocation(i,str);
		//cout<<str<<"\n";
		fout<<str<<"\n";
	}
	fout.close();
	return;
}
void retrieve_zipcode(LinkedList<string>& table2,LinkedList<string>& table3)
{
	int t=table3.getListLength()+1;
	string str,zipcode;
	cout<<"Enter zip code: ";
	getline(cin,zipcode);
	for (int i=1;i<t;i++)
	{
		table3.printatlocation(i,str);
		if (str==zipcode)
		{
			table2.printatlocation(i,str);
			cout<<str<<"\n";
		}
	}
}
void menu()
{
	cout<<"=====================================\n";
	cout<<"Welcoming use address book\n";
	cout<<"1. Add a new address record(From input.txt)\n";
	cout<<"2. View an existing address record\n";
	cout<<"3. Delete an existing address record \n";
	cout<<"4. Modify an existing address record \n";
	cout<<"5. Save the entire address book in a file  \n";
	cout<<"6. Retrieve all address entries using zip code\n" ;
	cout<<"7. Print the entire address book on the screen \n" ;
	cout<<"8. Exit \n" ;
	cout<<"=====================================\n";
}