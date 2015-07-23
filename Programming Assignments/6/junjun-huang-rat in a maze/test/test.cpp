#include<queue>
#include<iostream>
#include <ctime> 
using namespace std;
//use goalbe value
#define N 12

//==============original data====
char org_data[N][N]={
{'#','#','#','#','#','#','#','#','#','#','#','#'},
 {'#','.','.','.','#','.','.','.','.','.','.','#'},
 {'.','.','#','.','#','.','#','#','#','#','.','#'},
 {'#','#','#','.','#','.','.','.','.','#','.','#'},
 {'#','.','.','.','.','#','#','#','.','#','.','.'} ,
 {'#','#','#','#','.','#','.','#','.','#','.','#'},
 {'#','.','.','#','.','#','.','#','.','#','.','#'},
 {'#','#','.','#','.','#','.','#','.','#','.','#'}	,
 {'#','.','.','.','.','.','.','.','.','#','.','#'}	,
 {'#','#','#','#','#','#','.','#','#','#','.','#'}	,
 {'#','.','.','.','.','.','.','#','.','.','.','#'}	,
 {'#','#','#','#','#','#','#','#','#','#','#','#'}
};

//==============test data====
char test_data[N][N];

//==============change char 2 int, then change move
int x_y[N][N];

//==============startx,y;endx,y.
int startX,startY,endX,endY;

//==============(BUG);get the rand data for 12*12.
//==============test lot of time, can't build possible maze.
void mazeGenerator()
{							
	srand(time(NULL));
	for(int i = 0;i < N;i++) {
		for(int j = 0;j < N;j++) {
			int ran_num=rand() % 100+1;
			if(ran_num%2==0)
				test_data[i][j]='#';
			else
				test_data[i][j]='.';
}//end build maze
}
}

//==============show the move
void mazeTraverse(int x,int y,char data[N][N])
{
	 data[x][y]='x';//change to X
	  for(int i = 0;i < N;i++) {
		  for(int j = 0;j < N;j++) {
			  cout<< data[i][j];
}
cout<<"\n";
}
}

//===========checkmove
int CheckMove(int x, int y, int& newX, int& newY, int direction,char data[N][N]) {
	//build temp
	int tempX = x;
	int tempY = y;

	switch(direction) {
case 0:
	tempX--;break;
case 1:
	tempX++;break;
case 2:
	tempY--;break;
case 3:
	tempY++;break;
}
	newX = tempX;
	newY = tempY;
	if(tempX < 0 || tempX >= N || tempY < 0 || tempY >= N) {
		return 0;
}

//move
if(data[tempX][tempY] == '.') {
return 1;
}
return 0;
}

//check uesed or not
int UesedOne(int x, int y) {
if(x_y[x][y] == 0) {
return 0;
}
return 1;
}
int isAim(int x, int y) {
if( x == (endX-1) && y == (endY-1)) {
return 1;
}
return 0;
}

int search(char data[N][N], int start_node) {
	int x;
	int y;
	int newX;
	int newY;
	int num = 0;
	queue<int> not_yet_explored;
	not_yet_explored.push(start_node);
	x_y[startX - 1][startY - 1] = 1;
	while(!not_yet_explored.empty()) {
		int node_to_explored = not_yet_explored.front();
		not_yet_explored.pop();
		x = node_to_explored / N;
		y = node_to_explored % N;
		num = x_y[x][y];
for(int i = 0;i < 4;i++) {
	if(CheckMove(x, y, newX, newY, i,data)) {
		
		if(isAim(newX, newY)) {
			if(num>0)
			{
			data[endX-1][endY-1]='x';
			cout<<"\nmove to( "<<endX<<" , "<<endY<<" )\n";
				mazeTraverse(newX,newY,data);
	cout<<"\n";
			}
			return num;
}
		if(!UesedOne(newX, newY)) {
			if(num>0){
			data[startX-1][startY-1]='x';
	cout<<"\nmove to( "<<newX+1<<" , "<<newY+1<<" )\n";
	mazeTraverse(newX,newY,data);
	cout<<"\n";
			}
	x_y[newX][newY] = num + 1;
	not_yet_explored.push(newX*N + newY);
}
}
}
}
}

//add fix

int getnum(char data[N][N], int start_node) {
int x;
int y;
int newX;
int newY;
int num = 0;
	queue<int> not_yet_explored;
	not_yet_explored.push(start_node);
	x_y[startX - 1][startY - 1] = 1;
while(!not_yet_explored.empty()) {
int node_to_explored = not_yet_explored.front();
not_yet_explored.pop();
x = node_to_explored / N;
y = node_to_explored % N;
num = x_y[x][y];
for(int i = 0;i < 4;i++) {
	if(CheckMove(x, y, newX, newY, i,data)) {
		if(isAim(newX, newY)) {
return num;
}
if(!UesedOne(newX, newY)) {
x_y[newX][newY] = num + 1;
not_yet_explored.push(newX*N + newY);
}
}
}
}
}



int main() {
	//show org data
	cout<<"this is original data for test:\n";
	for(int i = 0;i < N;i++) {
		for(int j = 0;j < N;j++) {
			cout<< org_data[i][j];
		}
		cout<<"\n";
	}

	//change org data  2 int
	for(int row = 0;row < N;row++) {
for(int col = 0;col < N;col++) {
if(org_data[row][col] == '.') {
x_y[row][col] = 0;
} else {
x_y[row][col] = -2;
}
}
}
	//cout<<"\nenter startX , startY , endX , endY\n";
		//cin >> startX >> startY >> endX >> endY;
	//get starty,,start x=0;
	startX=1;
	endX=11;
	int final_sy=0,final_ey=0,f_move=0,l_move=0;
	for(int row=0;row<N;row++)
		if(org_data[row][0]=='.')
		{
			for(int row1=0;row1<N;row1++)
			{
				if(org_data[row1][11]=='.')
				{
					cout<<"For test possible startX = 1 startY = "<<row+1<<" possible endX = 12 endY = "<<row1+1<<endl;
				startY=row+1;
				endY=row1+1;
				int temp_int=getnum (org_data, (startX-1)*N + startY-1);
				cout<<"For test the possible total move(0 = no way arrive endx,y) £º"<<temp_int<<endl;
				if(temp_int!=0)
				{
				if(f_move==0)
				{
				f_move=temp_int;
				final_sy=startY;
				final_ey=endY;
				}
				else
				{
				l_move==temp_int;
				if(l_move<f_move)
				{
				f_move=l_move;
				final_sy=startY;
				final_ey=endY;
				}
				}
				}
				
				}
			}
		}			   

	//get move
		if((final_sy!=0)&&(final_ey!=0))
		{
	cout<<"the enter x = 1,y = "<<final_sy<<" the out x = 12 y = "<<final_ey<<endl;
	cout << "Total minimum move is: "<<f_move<< endl;
		}
		else
			cout<<"No answer.\n";


		cout<<"enter yes for random data, or n for exit\n";
		char gogo;
		cin>>gogo;
		if(gogo=='n')
			exit(1);
//randomly data
			cout<<"\n\nthis is random data for test:\n";
mazeGenerator(); 
for(int i = 0;i < N;i++) {
for(int j = 0;j < N;j++) {
cout<< test_data[i][j];
}
cout<<"\n";
}
for(int row = 0;row < N;row++) {
for(int col = 0;col < N;col++) {
if(test_data[row][col] == '.') {
x_y[row][col] = 0;
} else {
x_y[row][col] = -2;
}
}
}
	//cout<<"\nenter startX , startY , endX , endY\n";
		//cin >> startX >> startY >> endX >> endY;

	startX=1;
	endX=11;
	final_sy=0,final_ey=0,f_move=0,l_move=0;
	for(int row=0;row<N;row++)
		if(test_data[row][0]=='.')
		{
			for(int row1=0;row1<N;row1++)
			{
				if(test_data[row1][11]=='.')
					{
					cout<<"For test possible startX = 1 startY = "<<row+1<<" possible endX = 12 endY = "<<row1+1<<endl;
							   startY=row+1;
				endY=row1+1;
				int temp_int=getnum (test_data, (startX-1)*N + startY-1);
				cout<<"For test the possible total move(0 = no way arrive endx,y) £º"<<temp_int<<endl<<endl;
				
				if(temp_int!=0)
				{
				if(f_move==0)
				{f_move=temp_int;
				final_sy=startY;
				final_ey=endY;  }
				else
				{
				l_move==temp_int;
				if(l_move<f_move)
				{
					f_move=l_move;
				final_sy=startY;
				final_ey=endY;
				}
				}
				}
				
				}
			}
		}	

		if((final_sy!=0)&&(final_ey!=0))
		{
	cout<<"the enter x = 1,y = "<<final_sy<<" the out x = 12 y = "<<final_ey<<endl;
	cout << "Total minimum move is: "<<f_move<< endl;
		}
		else
			cout<<"No answer.\n";

return 0;
}