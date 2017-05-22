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
	while(flag>=0&&man==1)
	{
		change=0;
		while(flag<n&&flag>=0&&count<=bushu&&man==1)
		{
			count++;
			cout<<flag<<","<<linshirongliang<<","<<linshivalue<<endl;
			// cout<<flag<<endl;
			if(linshirongliang+w[flag]<=c&&place[flag]==0)
			{
				linshivalue=linshivalue+v[flag];
				linshirongliang=linshirongliang+w[flag];
				place[flag]=1;
				flag+=1;
			}
			else if(linshirongliang+w[flag]>c&&place[flag]==0)
			{
				if(zongc<linshirongliang&&flag<n)
				{
					zongc=linshirongliang;
					zong=linshivalue;
					linshirongliang-=w[flag-1];
					linshivalue-=v[flag-1];
					place[flag-1]=0;
					flag++;
				}
				else if(flag<n)
				{
					
					// linshirongliang-=w[flag];
					// linshivalue-=v[flag];
					linshirongliang-=w[flag-1];
					linshivalue-=v[flag-1];
					place[flag-1]=0;
					flag++;
				}
			}
			else
			{
				while(place[flag]==1&&flag>=0)
				{
					flag--;
				}
			}
			if(flag==0)
			{
				if(zongc<linshirongliang)
				{
					zongc=linshirongliang;
					zong=linshivalue;
					
				}
				man=0;
			}
		}
		place[flag]=0;
		linshirongliang-=w[flag];
		linshivalue-=v[flag];
		flag--;
		for(int i=1;i<n;i++)
		{
			if(place[i]==1)
				man=1;
		}
		if(flag==0)
			man=0;
	}
	cout<<zong<<","<<zongc<<endl;
}
