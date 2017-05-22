#include<iostream>
using namespace std;
const int MAX = 100;
int P[MAX],N[MAX],T[MAX];
int Cost,NCost;
void back_try(int s,int n,int C[4][4])
{
	for(int i = 1; i<n; i++)
	if(NCost+C[N[s]][i]<Cost && !T[i])
	{
	P[s] = i; //记录
	NCost = NCost+C[N[s]][i];
	T[i] = 1;
	N[s+1] = i;
	if(s == n-2)
	{
	if(NCost+C[N[i]][1]<Cost) //选新的路径
	{
	for(int j=0; j<n; j++)
	P[j] = N[j];
	Cost = NCost + C[N[n]][1];
	}
	}
	else
	back_try(s+1,n,C);
	//去掉记录
	NCost = NCost - C[N[s]][i];
	T[i] = 0;
	N[s+1] = 0;
	}
}


void TSP(int n, int C[4][4])
{//初始化
	for(int i = 0; i<n; i++)
	{
	P[i] = 0;
	N[i] = 0;
	T[MAX] = 0;
	}
	Cost = 10000;
	NCost = 0;
	back_try(0,n,C);
	cout<<"找到最小开销路径："<<endl;
	for(int j = 0; j<4; j++)
	cout<<"->"<<P[j];
	cout<<endl;
	cout<<endl<<"最小开销为："<<endl<<Cost<<endl;
}


int main()
{
int city[4][4] ={{0,3,6,7},
{5,0,2,3},
{6,4,0,2},
{3,7,5,0}};
TSP(4,city);
system("pause");
return 0;
}

