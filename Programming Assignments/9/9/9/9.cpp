#include<iostream>
#include<fstream>
using namespace std;

struct node
{
char ch;
node *next;
node *child;
};

node *Node_build(node *head,char ch)//²åÈë
{
node *tmp = new node;
tmp->ch = ch;
tmp->child = NULL;
tmp->next = head;
return tmp;
}

void add_data(node *&root, char *word,int i=0)
{
if(root!=NULL)
   if(root->ch == '/')
    return add_data(root->child,word,i);
bool exist=0;
node *tmp = root;
while(tmp!=NULL)
{
   if(tmp->ch == word[i])
   {
	   exist=1;
	   break;
   }
   else
    tmp = tmp->next;
}

//¼ÓÈë
if(exist==0)
   root = Node_build(root,word[i]);
if(word[i]==' ')
   return;
else
   return add_data(root->child,word,++i);
}

bool find_data(node *&root,char *word,int i=0)
{
if(root!=NULL)
   if(root->ch == '/')
    return find_data(root->child,word,i);


bool exist=0;
node *tmp = root;
while(tmp!=NULL)
{
   if(tmp->ch == word[i])
   {
	   exist=1;
	   break;
   }
   else
    tmp = tmp->next;
}

if(exist==0)
   return 0;

if(word[i]=='\0')
   return 1;
else
   return find_data(tmp->child,word,++i);
}

int main()
{
bool find = 0;
//new 
node *root = new node;
root->ch = '/';
root->child = root->next = NULL;
//new end

//test
cout<<"Test Spell Checker\nThe dictionary from Dict.txt, The test data Input.txt\n\n";
ifstream fin_dicit("dict.txt");
int no;
fin_dicit>>no;
char ch_word[20];
for(int i=0;i<no;i++)
{
	fin_dicit>>ch_word;
	cout<<"Add "<<ch_word<<" from dictionary\n";
	add_data(root,ch_word);
}
fin_dicit.close();

//display input
ifstream fin_dispaly("input.txt");
cout<<"\nThe input data: ";
while(!fin_dispaly.eof())
{
	fin_dispaly>>ch_word;
	cout<<ch_word<<" ";
}
fin_dispaly.close();

cout<<"\n\nsearch in dictionary\n\n";
ifstream fin_input("input.txt");
while(!fin_input.eof())
{
	fin_input>>ch_word;
	cout<<"looking for : "<<ch_word<<endl;
	find = find_data(root,ch_word);
	if(find)
		cout<<"find "<<ch_word<<" in dictionary.\n";
}
fin_input.close();

return 0;
}
								  