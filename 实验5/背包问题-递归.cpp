#include	<iostream>
#include	<cstring>
#include <time.h>
#include <stdlib.h> 
using namespace std;
int zong,zongc;
int take[1000];
void getTime()
{
	time_t t = time(0);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z", localtime(&t));
	puts(tmp);
}
void f(int v[],int w[],int n,int position,int c,int value,int rongliang,int take[])
{
	// for(int i=0;i<n;i++)
	// {
	// 	if(take[i]==0&&take[position]==0)
	// 		cout<<i<<',';
	// }
	if(position==n)
	{
		if(zong<value)
		{
			zong=value;
			zongc=rongliang;
			return;
		}
		return;
	}
	if(rongliang+w[position]<=c)
	{
		value+=v[position];
		rongliang+=w[position];
		take[position]=1;
		f(v,w,n,position+1,c,value,rongliang,take);
		value-=v[position];
		rongliang-=w[position];
		// for(int i=0;i<n;i++)
		// {
		// 	if(take[i]==0&&take[position]==1)
		// 		cout<<i<<',';
		// }
		// cout<<endl;
		take[position]=0;
		f(v,w,n,position+1,c,value,rongliang,take);
	}
	else
	{
		if(zong<value)
		{
			zong=value;
			zongc=rongliang;
			return;
		}
		return;
	}
}
int main()
{
	int v[5][1000];
	int w[5][1000];
	int c,n;
	cout<<"duo shao rong liang\n";
	cin>>c;
	cout<<"ji zhong wu pin?\n";
	cin>>n;
	zongc=0;
	zong=0;
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<"di "<<i+1<<" ge de v\n";
	// 	cin>>v[i];
	// 	cout<<"di "<<i+1<<" ge de w\n";
	// 	cin>>w[i];
	// }
	memset(take,0,sizeof(take));
	cout << "递归前" << endl;
	srand((unsigned)time(NULL));
	for (int i2 = 0; i2 < 5; i2++)
	{
		for (int i = 0; i < n; i++)
		{
			while(1)
			{
				v[i2][i] = rand(); 
				if(v[i2][i]<c/3&&v[i2][i]>=0)
					break;
			}
			while(1)
			{
				w[i2][i] = rand();
				if(w[i2][i]<c/3&&v[i2][i]>=0)
					break;
			}
		}
	}
	for (int i2 = 0; i2 < 5; i2++)
	{
		zong=0;
		zongc=0;
		getTime();
		f(v[i2],w[i2],n,0,c,0,0,take);
		getTime();
		cout << endl << "递归后" << endl;
		cout<<"v:"<<zong<<",c:"<<zongc<<endl;
	}
}
