#include	<iostream>
#include	<cstring>
#include	<cmath>
using namespace std;
int zong,zongc;
int main()
{
	int v[1000];
	int w[1000];
	int place[1000];
	int flag;
	int position;
	int c,n;
	int count=0;
	cout<<"duo shao rong liang\n";
	cin>>c;
	cout<<"ji zhong wu pin?\n";
	cin>>n;
	zongc=0;
	zong=0;
	int bushu=pow(2,n);
	for(int i=0;i<n;i++)
	{
		cout<<"di "<<i+1<<" ge de v\n";
		cin>>v[i];
		cout<<"di "<<i+1<<" ge de w\n";
		cin>>w[i];
	}
	position=0;
	memset(place,0,sizeof(place));
	flag=0;
	place[flag]=0;
	int linshirongliang=0;
	int linshivalue=0;
	int change=0;
	place[flag]=0;
	int man=1;
	while(flag>=0)
	{
		while(flag<n)
		{
			if(linshirongliang+w[flag]<=c)
			{
				place[flag]++;
				linshivalue+=v[flag];
				linshirongliang+=w[flag];
			}
			flag++;
		}
		if(linshirongliang>zong)
		{
			zong=linshivalue;
			zongc=linshirongliang;
		}
		if(flag>=n)
		{
			flag-=1;
		}
		while(place[flag]!=1&&flag>=0)
		{
			flag--;
		}
		if(flag>=0)
		{
			place[flag]=0;
			linshirongliang-=w[flag];
			linshivalue-=v[flag];
			flag++;
		}
	}
	cout<<zong<<","<<zongc<<endl;
}
