#include <iostream> 
#include <cstring>
using namespace std;
char a[100000][5];
int b[100000];
struct haffnode
{
	int weight;
	char c;
	int left;
	int right;
	int flag;
};
int main()
{
	int n;
	cout<<"ÊäÈë¼¸×éÊý¾Ý?\n";
	cin>>n;
	memset(a,'\0',sizeof(a));
	cout<<"ÊäÈë×Ö·û\n";
	for(int i1=0;i1<n;i1++)
	{
		cin>>a[i1];
	}
	memset(b,0,sizeof(b));
	cout<<"ÊäÈëÈ¨Öµ\n";
	for(int i2=0;i2<n;i2++)
	{
		cin>>b[i2];
	}
	int min;
	for(int i1=0;i1<n;i1++)
	{
		min=i1;
		for(int i2=i1;i2<n;i2++)
		{
			if(b[i2]<b[min])
				min=i2;
		}
		int i3=b[i1];
		char a2[5];
		strcpy(a2,a[i1]);
		b[i1]=b[min];
		strcpy(a[i1],a[min]);
		b[min]=i3;
		strcpy(a[min],a2);
	}
	for(int i1=0;i1<n;i1++)
	{
		cout<<b[i1]<<","<<a[i1]<<endl;
	}
}
