#include<iostream>
#include<cstring>
using namespace std;
void s(int a[],int b,int c,int d[],int e[])
{
	if(b==c)
	{
		for(int i=0;i<c;i++)
			if(e[i]==0)
				return;
		for(int i=0;i<c;i++)
			cout<<d[i]<<" ";
		cout<<endl; 
		return;
	} 
	for(int i=0;i<c;i++)
	{ 
		if(e[i]==1)
		{
			continue;
		}
		d[b]=a[i];
		e[i]=1;
		s(a,b+1,c,d,e);
		e[i]=0;
	}
}
int main()
{
	int n;
	cout<<"¼¸¸öÊý×Ö?\n";
	cin>>n;
	int merge[n+1];
	int merge2[n+1],place[n+1];
	for(int i=0;i<n;i++)
		place[i]=0;
	for(int i=0;i<n;i++)
		cin>>merge[i];
	s(merge,0,n,merge2,place);
}
