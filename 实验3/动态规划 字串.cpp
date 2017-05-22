#include	<iostream>
#include	<cstring>
using namespace std;
int main()
{
	char a[200];
	char b[200];
	while(1)
	{
		cin>>a>>b;
		int i1,i2;
		int result=0;
		int m[200][200];
		int placex;
		int placey;
		for(i1=0;i1<=strlen(a);i1++)
		{
			for(i2=0;i2<=strlen(b);i2++)
			{
				if(i1==0||i2==0)
					m[i1][i2]=0;
				else if(a[i1-1]==b[i2-1])
				{
					m[i1][i2]=m[i1-1][i2-1]+1;
					// result=result>m[i1][i2]?result:m[i1][i2];
					if(result<m[i1][i2])
					{
						result=m[i1][i2];
						placex=i1;
						placey=i2;
					}
				}
				else
					m[i1][i2]=0;
			}
		}
		char result2[200];
		memset(result2,'\0',sizeof(result2));
		int count=0;
		while(m[placex][placey]>0)
		{
			// cout<<placex<<",";
			result2[count]=a[placex-1];
			placex--;
			placey--;
			count++;
		}
		cout<<"字串是:";
		for(i1=strlen(result2)-1;i1>=0;i1--)
		{
			cout<<result2[i1]<<",";
		}
		cout<<endl;
		for(i1=0;i1<=strlen(a);i1++)
		{
			for(i2=0;i2<strlen(b);i2++)
			{
				cout<<m[i1][i2];
			}
			cout<<endl;
		}
		cout<<"长度是:"<<result<<endl;
	}
}
