#include<iostream>
#include<new>
#include<ctime>
#include<cmath>
#include<cstdlib>
using namespace std;


//每一台 飞机
class airplane{
public:
	int id;
	int tm;
};


template<class Type>
class Queue{
public:
	Queue(int=6);
	void Add(const Type & item);
	Type * Delete(Type &);
	bool IsFull();
	bool IsEmpty();
	int Size();
	void QueueEmpty();
	void QueueFull();
private:
	int front,rear;
	Type*queue;
	const int MaxSize;
};

template<class Type> 
Queue<Type>::Queue(int Max):MaxSize(Max){
	queue=new Type[MaxSize];
	front=rear=0;
}

template<class Type>
Type * Queue<Type>::Delete(Type & x){
	if(IsEmpty()){QueueEmpty();return 0;}
	x=queue[++front%=MaxSize];
	return & x; 
}

template<class Type>
void Queue<Type>::Add(const Type & x){
	int k=(rear+1)%MaxSize;
	if(IsFull())QueueFull();
	else queue[rear=k]=x;
}

template<class Type>
bool Queue<Type>::IsFull(){
	int k=(rear+1)%MaxSize;
	if(front==k)return true;
	else return false;
}

template<class Type>
bool Queue<Type>::IsEmpty(){
	if(front==rear)return true;
	else return false;
}

template<class Type>
void Queue<Type>::QueueFull(){
	cout<<"(Full)";
}

template<class Type>
void Queue<Type>::QueueEmpty(){
	cout<<"(Empty)";
}


template<class Type>
int Queue<Type>::Size(){
	if(rear>=front)return rear-front;
	else return rear-front+MaxSize;
}





enum action{ARRIVE,FLY};
class Airport{
public:
	Airport();
	void Run();//模拟run
private:
	Queue<airplane> airland;//land队列
	Queue<airplane> airfly;//fly队列
	double expectland;
	double expectfly;
	int nowtime;//当前时间
	int endtime;//总时间
	int notime;//free时间
	int landwait;//land 等待时间
	int flywait;//fly等待时间
	int nland;//总降落数
	int nairplanes;//总飞机数
	int nNoServe;//拒绝数
	int nfly;//起飞数
	void SetRand();//设置种子
	int PRand(double &expectvalue);//泊松函数
	airplane*Newairplane(airplane & p,action kind);//新加飞机
	void NoServe(airplane & p,action kind);//拒绝
	void Land(airplane & p,int);//降落操作
	void Fly(airplane & p,int);//起飞操作
	void Freeplane();//处理空闲
	void GetCalculate();//总结
};


//获得时间
Airport::Airport(){
	cout<<"Simulation Time Minutes (Default=60 if enter 0):";
	cin>>endtime;
	if (endtime==0){endtime=60;}
	notime=landwait=nland=nairplanes=nNoServe=nfly=flywait=0;//初始化
	SetRand();
	//test data
	//起飞，降落比例.
	cout<<"The land and fly proportion is 1/1(land/fly)\n";
	expectland=1;
	expectfly=1;
}

void Airport::Run(){ 
	int pri;
	airplane p;
	for(nowtime=1;nowtime<=endtime;nowtime++){
		cout<<"\nThe "<<nowtime<<" Minutes";
		pri=PRand(expectland);
		for(int i=1;i<=pri;i++){
			p=*Newairplane(p,ARRIVE);
		if(airland.IsFull())NoServe(p,ARRIVE);else {airland.Add(p);if(1!=airland.Size())cout<<" waiting on runway.";}
		}

		pri=PRand(expectfly);
		for(int i1=1;i1<=pri;i1++){
			p=*Newairplane(p,FLY);
 if(airfly.IsFull())NoServe(p,FLY);else {airfly.Add(p);if(1!=airland.Size()+airfly.Size())cout<<" waiting on runway.";}
		}

		if(airland.IsEmpty())Freeplane();
		if(!airland.IsEmpty()){p=*airland.Delete(p);Land(p,3);}
		else if(!airfly.IsEmpty()){p=*airfly.Delete(p);Fly(p,3);}
	}
	GetCalculate();
}

void Airport::SetRand(){
	srand((unsigned int)(time(NULL)%100000));
}

int Airport::PRand(double &expectvalue){
	int n=0;
	double limit;
	double x;
	limit=exp(-expectvalue);
	x=(rand()%1000)/(double)1000;
	while(x>limit){
		n++;
		x*=(rand()%1000)/(double)1000;
	}
	return n;
}

airplane*Airport::Newairplane(airplane & p,action kind){//新加飞机 
	nairplanes++;
	p.id=nairplanes;p.tm=nowtime;
	switch(kind){
		case ARRIVE:
			cout<<"\n          Airplane "<<nairplanes<<" want to land.";
			break;
		case FLY:
			cout<<"\n          Airplane "<<nairplanes<<" want to fly.";
			break;
	}
	return &p;
}


//拒绝服务
void Airport::NoServe(airplane & p,action kind){ 
	switch(kind){
		case ARRIVE:
			cout<<""<<"Sorry!!No free runway, please go other airport. ";
			break;
		case FLY:
			cout<<""<<"Sorry!!No free runway, cancel the fly. ";
			break;
	}
	++nNoServe;
}

//降落飞机 
void Airport::Land(airplane & p,int num){
	int wait;
	wait=nowtime-p.tm;
	cout<<"\n          Airplane "<<p.id<<" Landing, waiting time: "<<wait<<" minutes";
	nland++;
	landwait+=wait;
}


//起飞飞机
void Airport::Fly(airplane & p,int num){ 
	int wait;
	wait=nowtime-p.tm;
	cout<<"\n          Airplane "<<p.id<<" Flying, waiting time: "<<wait<<" minutes";
	nfly++;
	flywait+=wait;
}

//机场空闲 
void Airport::Freeplane(){
	cout<<"\n          The runway is free.";
	notime++;
}


//统计数据 
void Airport::GetCalculate(){
	cout<<"\n\n\n\nFor test. Get calculate:";
	cout<<"\nTotal Time: "<<endtime<<" minutes";
	cout<<"\nTotal Airplanes: "<<nairplanes;
	cout<<"\nTotal Land:"<<nland;
	cout<<"\nTotal Fly:"<<nfly;
	cout<<"\nTotal can't land and fly (Sorry!!No free runway):"<<nNoServe;
	cout<<"\nLeft for land"<<airland.Size();
	cout<<"\nLeft for fly"<<airfly.Size()<<"\n";
	if(endtime>0)cout<<"\nPercent for free runway:"<<((double)notime/endtime)*100.0;
	if(nland>0)cout<<"\nAverage time for waiting land:"<<(double)landwait/nland;
	if(nfly>0)cout<<"\nAverage time for waiting fly:"<<(double)flywait/nfly;
}





int main()
{
	Airport test;
	test.Run();
	cout<<endl;
	return 0;
}