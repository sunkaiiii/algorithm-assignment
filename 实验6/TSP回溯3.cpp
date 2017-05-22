#include	<iostream>
#include    <cstring>
#include 	<time.h>
#include <stdlib.h> 
using namespace std;
#define NUM 100  
int n;     
int a[NUM][NUM];  
int x[NUM];     
int bestx[NUM];     
int cc;         
int bestc;      
int NoEdge=-1;      
int jieguo[NUM];
void getTime()
{
	time_t t = time(0);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z", localtime(&t));
	puts(tmp);
}
void swap(int &a,int &b)
{
	int c;
	c=a;
	a=b;
	b=c;
} 
void init()  
{  
    for(int i=0;i<NUM;i++)  
    {  
        for(int j=0;j<NUM;j++)  
        {  
            a[i][j]=NoEdge;  
        }  
    }  
    bestc=NoEdge;  
    cc=0;  
    for(int i=1;i<=n;i++)  
    {  
        x[i]=i;  
    }  
}  
  
void BackTrack(int t,int biaoji[])      
{  
 
    if(t==n)  
    {  
        if(a[x[n-1]][x[n]]!=NoEdge && (a[x[n]][1]!=NoEdge) &&  
                (cc+a[x[n-1]][x[n]]+a[x[n]][1]<bestc ||bestc==NoEdge))  
        {  
             for(int i=1;i<=n;i++)  
             {  
                bestx[i]=x[i];  
             }  
             bestc=cc+a[x[n-1]][x[n]]+a[x[n]][1];  
             for(int i=1;i<=n;i++)
             {
                jieguo[i]=biaoji[i];
             }
        }  
    }  
    else  
    {  
        for(int i=t;i<=n;i++)  
        {  
         
            if(a[x[t-1]][x[i]]!=NoEdge && (cc+a[x[t-1]][x[i]]<bestc ||bestc==NoEdge)&&a[t-1][i]>0)  
            {  
                swap(x[t],x[i]);  
                cc+=a[x[t-1]][x[t]];
//                cout<<cc<<",";   
                biaoji[t]=i;
                BackTrack(t+1,biaoji);  
                biaoji[t]=0;
                cc-=a[x[t-1]][x[t]];  
                swap(x[t],x[i]);  
            } 
        }  
    }  
  
}
void BackTrack2(int t,int biaoji[])      
{  
 
    if(t==n)  
    {  
        if(a[x[n-1]][x[n]]!=NoEdge && (a[x[n]][1]!=NoEdge) &&  
                (cc+a[x[n-1]][x[n]]+a[x[n]][1]<bestc ||bestc==NoEdge))  
        {  
             for(int i=1;i<=n;i++)  
             {  
                bestx[i]=x[i];  
             }  
             bestc=cc+a[x[n-1]][x[n]]+a[x[n]][1];  
             for(int i=1;i<=n;i++)
             {
                jieguo[i]=biaoji[i];
             }
        }  
    }  
    else  
    {  
        for(int i=t;i<=n;i++)  
        {  
         
            if(a[x[t-1]][x[i]]!=NoEdge &&a[t-1][i]>0)  
            {  
                swap(x[t],x[i]);  
                cc+=a[x[t-1]][x[t]];
//                cout<<cc<<",";   
                biaoji[t]=i;
                BackTrack2(t+1,biaoji);  
                biaoji[t]=0;
                cc-=a[x[t-1]][x[t]];  
                swap(x[t],x[i]);  
            } 
        }  
    }  
  
}
int main()
{
    while(1){
    	cout<<"输入顶点数"<<endl;
    	cin>>n;
        init();
        srand((unsigned)time(NULL));
        int b[NUM][NUM];
    	cout<<"输入矩阵"<<endl;
    	 for(int i=1;i<=n;i++)  
        {  
            for(int j=1;j<=n;j++)  
            {  
//                cin>>a[i][j]; 
				while(1){
				   a[i][j]=rand();
				   b[i][j]=a[i][j];
				   if(a[i][j]>=0&&a[i][j]<50){
				   		cout<<a[i][j]<<" ";
				   		break;
				   	}
				}
            }  
            cout<<endl;
        }  
        int biaoji[NUM];
        memset(biaoji,0,sizeof(biaoji));
        biaoji[1]=1;
        int t1=time(0);
    	BackTrack(2,biaoji);
    	int t2=time(0);
//    	memset(biaoji,0,sizeof(biaoji));
//    	init();
//    	for(int i=1;i<=n;i++)  
//        {  
//            for(int j=1;j<=n;j++)  
//            {  
//            	a[i][j]=b[i][j];
//            }
//        }
//        int t3=time(0);
//    	 BackTrack2(2,biaoji);
//    	 int t4=time(0);
    	cout<<"1：花费时间为:"<<t2-t1<<"秒"<<endl;
//    	cout<<"2：花费时间为:"<<t4-t3<<"秒"<<endl;
    	cout<<"最小开销"<<bestc<<endl;
    	cout<<"路径为:";
   	for(int i=1;i<=n;i++)
   	{
   		cout<<bestx[i]<<",";
   	}
        // for(int i=1;i<n;i++)
        //  {
        //     if(jieguo[i]>0)
        //      cout<<jieguo[i]<<",";
        //  }
         cout<<endl;
//        cout<<bestc;
       cout<<endl;
    }
}
