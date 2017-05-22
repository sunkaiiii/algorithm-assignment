#include	<iostream>
#include	<cstring>
using namespace std;
int zong,zongc;
int main()
{
	int v[1000];
	int w[1000];
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
	for(position=0;position<n;position++)
	{
		for(int i=position;i<n;i++)
		{
			int values=0;
			int linshirongliang=0;
			if(linshirongliang+w[i]<=c)
			{
				linshirongliang+=w[i];
				values+=v[i];
				for(int i2=i+1;i2<n;i2++)
				{
					if(linshirongliang<=c)
					{
						if(zong<values)
						{
							zongc=linshirongliang;
							zong=values;
						}
					}
					values+=v[i2];
					linshirongliang+=w[i2];
				}
				for(int i2=i+1;i2<n;i2++)
				{
					values-=v[i2];
					linshirongliang-=w[i2];
					if(linshirongliang<=c)
					{
						if(zong<values)
						{
							zong=values;
							zongc=linshirongliang;
						}
					}
				}
				linshirongliang-=w[i];
				values-=v[i];
			}
		}
	}
	cout<<"v: "<<zong<<"c: "<<zongc<<endl;
}
