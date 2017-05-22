#include	<iostream>
#include	<cstring>
using namespace std;\
void compare(char a[],char b[]);
char result[2000];
void f(char a[],int d,char b[],char c[],int place)
{
	if(d==strlen(a)){
		compare(c,b);
		return;
	}
	else
	{
		c[place]=a[d];
		f(a,d+1,b,c,place+1);
		c[place]='\0';
		f(a,d+1,b,c,place);
		compare(c,b);
		// compare(c,b);
	}
}
void compare(char a[],char b[])
{
	int i4=0;
	int result2Len=0;
	for(int i4=0;i4<strlen(b);i4++)
	{
		if(a[result2Len]==b[i4])
			result2Len++;
		if(result2Len==strlen(a))
		{
			// cout<<result2<<endl;
			if(strlen(result)<strlen(a))
				strcpy(result,a);
		}
	}
}
int main()
{
	char a[2000];
	char b[2000];
	char c[2000];
	memset(c,'\0',sizeof(c));
	cout<<"ÇëÊäÈëA"<<endl;
	cin>>a;
	cout<<"ÇëÊäÈëB"<<endl;
	cin>>b;
	memset(result,'\0',sizeof(result));
	f(a,0,b,c,0);
	cout<<result<<endl;
}
