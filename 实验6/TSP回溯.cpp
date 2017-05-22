#include	<iostream>
#include    <cstring>
using namespace std;
//TSP问题,Travel Salesman Problem,又称为货担郎问题,邮递员问题  
//题目要求:从n个城市中的某一个出发,不重复的走网其余n-1个城市,并且回到起始点,  
//在所有可能的线路中,找出路径最短的一条  
  
//算法:还是用回溯法,解空间结构为排列树  
#define NUM 100  
int n;      //图G的顶点个数  
int a[NUM][NUM];    //图G的邻接矩阵  
int x[NUM];     //当前解  
int bestx[NUM];     //最优解,顺序输出即可  
int cc;         //当前费用  
int bestc;      //最优费用  
int NoEdge=-1;      //无边标记  
int jieguo[NUM];
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
  
void BackTrack(int t,int biaoji[])       //t从2开始  
{  
    //到达第n个节点  
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
            //如果上一个节点和它此后的节点有边,并且费用不高于现有的最优费用(bestc==NoEdge表示第一次)  
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
  
}//注,此时默认x[1]==1,即从第一个节点出发  
int main()
{
    while(1){
    	cout<<"输入顶点数"<<endl;
    	cin>>n;
        init();
    	cout<<"输入矩阵"<<endl;
    	 for(int i=1;i<=n;i++)  
        {  
            for(int j=1;j<=n;j++)  
            {  
                cin>>a[i][j];  
            }  
        }  
        int biaoji[NUM];
        memset(biaoji,0,sizeof(biaoji));
        biaoji[1]=1;
    	BackTrack(2,biaoji);
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
