#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
 
using namespace std;
class infix2postfix
{
private:
 char infix[100];
 char stack[200];
 int top;
 int r;
 char postfix[100];
public:
 void convert(); 
 int input_p(char);
 int stack_p(char);
 int rank(char);
};
 
int infix2postfix::input_p(char c)
{
 if(c=='+' || c=='-')
  return 1;
 else if(c=='*' || c=='/')
  return 3;
 else if(isalpha(c)!=0)
  return 7;
 else if(c=='(')
  return 9;
 else if(c==')')
  return 0;
 else
 {
  cout<<"Invalid infix2postfix: input error"<<endl;
  exit(0);
 }
}
 
int infix2postfix::stack_p(char c)
{
 if(c=='+' || c=='-')
  return 2;
 else if(c=='*' || c=='/')
  return 4;
 else if(isalpha(c)!=0)
  return 8;
 else if(c=='(')
  return 0;
 else
 {
  cout<<"Error 0\n";
  exit(0);
 }
}
 
int infix2postfix::rank(char c)
{
 if(c=='+' || c=='-')
  return -1;
 else if(c=='*' || c=='/')
  return -1;
 else if(isalpha(c)!=0)
  return 1;
 else
 {
  cout<<"Error 1\n";
  exit(1);
 }
}
 
void infix2postfix::convert()
{
 cout<<"\n*************************************************\n"
<<"infix to postfix\n"
<<"\n*************************************************\n";
 cout<<"Enter an infix(ex:a+b-c):\n";
 cin>>infix;
 int l=strlen(infix);
 
 infix[l]=')';
 infix[l+1]=' ';
 

 top=1;
 stack[top]='(';
 
 r=0;
 int x=-1;
 
 int i=0;
 char next=infix[i];
 
 while(next!=' ')
 {

  while( input_p(next) < stack_p(stack[top]) )
  {
   if(top<1)
   {
    cout<<"Error 2\n";
    exit(2);
   }
 
   postfix[++x]=stack[top];
   top--;
 
   r=r+rank(postfix[x]);
 
   if(r<1)
   {
    cout<<"Error 3\n";
    exit(3);
   }
  }
 
  if(input_p( next ) != stack_p( stack[top]))
   stack[++top]=next;
  else
   top--;
 
  i++;
  next=infix[i];
 }
 postfix[++x]=' ';
 
 if(r!=1 || top!=0)
 {
  cout<<"Error 4\n";
  exit(4);
 }
 cout<<"\nThe  postfix is \n";
 for (i=0;i<l;i++)
 {
	 if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||(postfix[i]>='a'&&postfix[i]<='z')||(postfix[i]>='A'&&postfix[i]<='Z'))
	 cout<<postfix[i];
 }
	 
 cout<<endl;
}
int main()
{
 infix2postfix test;
 test.convert();
 return 0;
}