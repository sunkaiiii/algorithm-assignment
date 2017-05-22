#include	<iostream>
#include    <cstring>
using namespace std;
//TSP����,Travel Salesman Problem,�ֳ�Ϊ����������,�ʵ�Ա����  
//��ĿҪ��:��n�������е�ĳһ������,���ظ�����������n-1������,���һص���ʼ��,  
//�����п��ܵ���·��,�ҳ�·����̵�һ��  
  
//�㷨:�����û��ݷ�,��ռ�ṹΪ������  
#define NUM 100  
int n;      //ͼG�Ķ������  
int a[NUM][NUM];    //ͼG���ڽӾ���  
int x[NUM];     //��ǰ��  
int bestx[NUM];     //���Ž�,˳���������  
int cc;         //��ǰ����  
int bestc;      //���ŷ���  
int NoEdge=-1;      //�ޱ߱��  
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
  
void BackTrack(int t,int biaoji[])       //t��2��ʼ  
{  
    //�����n���ڵ�  
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
            //�����һ���ڵ�����˺�Ľڵ��б�,���ҷ��ò��������е����ŷ���(bestc==NoEdge��ʾ��һ��)  
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
  
}//ע,��ʱĬ��x[1]==1,���ӵ�һ���ڵ����  
int main()
{
    while(1){
    	cout<<"���붥����"<<endl;
    	cin>>n;
        init();
    	cout<<"�������"<<endl;
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
    	cout<<"��С����"<<bestc<<endl;
    	cout<<"·��Ϊ:";
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
