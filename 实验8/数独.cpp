#include	<iostream>
#include	<cstring>
using namespace std;
int a[3][3];
int ok;
int place[10];
void sudoko(int n)
{
	cout<<n<<endl;
	if(n==9)
	{
		for(int i=0;i<3;i++)
		{
			for(int i2=0;i2<3;i2++)
			{
				cout<<a[i][i2]<<",";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	else
	{
		ok=1;
		if(a[n/3][n%3]==-1)
		{
			for(int i=1;i<=9;i++)
			{
				ok=1;
				
					for(int i2=0;i2<n%3;i2++)
					{
						if(i==a[n/3][i2])
							ok=0;
					}
					for(int i2=0;i2<n/3;i2++)
					{
						if(i==a[i][n%3])
							ok=0;
					}
					if(place[i]==1)
						ok=0;
					if(ok==1)
					{
						a[n/3][n%3]=i;
						place[i]=1;
						sudoko(n+1);
						a[n/3][n%3]=-1;
						place[i]=0;
					}	
			}
		}
		else
		{
			sudoko(n+1);
		}
	}
}
int main()
{
	// int a[3][3];
	memset(place,0,sizeof(place));
	for(int i=0;i<3;i++)
	{
		for(int i2=0;i2<3;i2++)
		{
			cin>>a[i][i2];
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int i2=0;i2<3;i2++)
		{
			if(a[i][i2]>0)
				place[a[i][i2]]=1;
		}
	}
	sudoko(0);
}
