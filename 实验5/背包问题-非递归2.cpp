#include	<iostream>
#include	<cstring>
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
	cout<<"duo shao rong liang\n";
	cin>>c;
	cout<<"ji zhong wu pin?\n";
	cin>>n;
	zongc=0;
	zong=0;
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
	int linshirongliangstack[1000];
	int linshivaluestack[1000];
	int linshiflagsstack[1000];
	int linshivalue=0;
	int linshirongliang=0;
	int man=1;
	position=n-1;
	while(c!=linshirongliang&&man)
	{
		if(linshirongliang+w[0]<=c&&position>=0)
		{
			if(zong<linshivalue)
			{
				zongc=linshirongliang;
				zong=linshivalue;
			}
			linshirongliangstack[flag]=w[position];
			linshivaluestack[flag]=v[position];
			linshiflagsstack[flag]=position;
			linshivalue+=v[position];
			linshirongliang+=w[position];
			flag++;
			position--;
		}
		else
		{
			if(position<0)
			{
				flag--;
				linshirongliang-=linshirongliangstack[flag];
				linshivalue-=linshivaluestack[flag];
				if(zong<linshivalue)
				{
					zongc=linshirongliang;
					zong=linshivalue;
				}
			}
			if(flag<0)
			{
				man=0;
			}
			else
			{
				flag--;
				position=linshiflagsstack[flag]-1;
				linshirongliang-=linshirongliangstack[flag];
				linshivalue-=linshivaluestack[flag];
				if(zong<linshivalue)
				{
					zongc=linshirongliang;
					zong=linshivalue;
				}
			}
		}
	}
	cout<<zong<<","<<zongc<<endl;
}
