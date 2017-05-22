#include	<iostream>
#include	<cstring>
using namespace std;
int main()
{
	char a[200];
	char b[200];
	while(1)
	{
		cin>>a;
		cin>>b;
		int m[200][200];
		int count=0;
		int i1,i2;
		cout<<a<<","<<b<<"\n";
		memset(m,0,sizeof(m));
		for(i1=0;i1<strlen(a);i1++)
		{
			for(i2=0;i2<strlen(b);i2++)
			{
				if(i1==0)
				{
					if(a[i1]==b[i2])
						count=1;
					m[i1+1][i2+1]=count;
				}
				else
				{
					if(a[i1]==b[i2])
						m[i1+1][i2+1]=m[i1][i2]+1;
					else
						m[i1+1][i2+1]=m[i1+1][i2]>m[i1][i2+1]?m[i1+1][i2]:m[i1][i2+1];
				}
			}
		}
		i1=strlen(a);
		i2=strlen(b);
		char result[200];
		memset(result,'\0',sizeof(result));
		int count2=0;
		while(i1>1||i2>1)
		{
			if(m[i1][i2]>m[i1-1][i2]&&m[i1][i2]>m[i1][i2-1]&&m[i1][i2]>m[i1-1][i2-1])
			{
				result[count2]=b[i2-1];
				count2++;
				//cout<<b[i2-1]<<","; 
				i1--;
			}
			else if(i2>1)
				i2--;
			else
				i1--;
		}
		cout<<"×ÓĞòÁĞÊÇ:";
		for(i1=strlen(result)-1;i1>=0;i1--)
			cout<<result[i1]<<",";
		cout<<endl;
		for(i1=0;i1<=strlen(a);i1++)
		{
			for(i2=0;i2<=strlen(b);i2++)
			{
				cout<<m[i1][i2]<<",";
			}
			cout<<endl;
		}
		cout<<m[strlen(a)][strlen(b)]<<endl;
	}
}
