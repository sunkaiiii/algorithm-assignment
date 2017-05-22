#include	<iostream>
#include	<cstring>
using namespace std;
int main()
{
	char a[2000];
	char b[2000];
	cout<<"ÇëÊäÈëA"<<endl;
	cin>>a;
	cout<<"ÇëÊäÈëB"<<endl;
	cin>>b;
	int maxLength;
	char result[2000];
	for(int i=0;i<strlen(a);i++)
	{
		for(int i2=i;i2<strlen(a);i2++)
		{
			int i4=0;
			char result2[2000];
			memset(result2,'\0',sizeof(result2));
			for(int i3=i;i3<=i2;i3++)
			{
				result2[i4]=a[i3];
				i4++;
				// cout<<i4<<",";
				// cout<<a[i]<<",";

				// if(a[i]==b[i3])
				// {
				// 	int i5=i3+1;
				// 	for(int i4=i+1;i4<=i2;i4++)
				// 	{
				// 		// cout<<a[i4]<<","<<b[i5]<<endl;
				// 		if(a[i4]!=b[i5])
				// 			break;
				// 		if(i4==i2)
				// 		{
				// 			int i7=0;
				// 			char result2[2000];
				// 			for(int i6=i;i6<=i2;i6++)
				// 			{
				// 				result2[i7]=a[i6];
				// 				i7++;
				// 			}
				// 			// cout<<result2<<endl;
				// 			strcpy(result,result2);
				// 			strcpy(result2,"");
				// 		}
				// 		i5++;
				// 	}
				// }
			}
			char d[2000];
			strcpy(d,b);
			// cout<<result2<<endl;
			if(strstr(d,result2)!=NULL)
			{
				// cout<<result2<<endl;
				if(strlen(result)<strlen(result2))
					strcpy(result,result2);
			}
		}
	}
	cout<<result<<endl;
}
