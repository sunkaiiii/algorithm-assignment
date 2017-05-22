#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <string>  
using namespace std;  
const int maxsize=100;  
int n,S;//n是有多少中物品，S是要凑足的重量  
bool visit[maxsize];//标记是否被访问过，别访问过标记为1，没有访问过为0  
int w[maxsize];//记录每一种物品的重量  
int q[maxsize];//相当于一个栈，存储被访问过的物品的编号  
int beibao()  
{  
    int top=-1,begin=0,sum=0;  
    int i;  
    while(top!=-2)  
    {  
        //从第一个物品开始循环  
        for(i=begin;i<n;i++)  
        {  
            //如果没有被访问过，并且加上重量之和小于S  
            if(!visit[i] && w[i]+sum<=S)  
            {  
                sum+=w[i];//在sum上加上当前物品的重量  
                q[++top]=i;//把物品的编号存入q[]中  
                begin=0;//从头开始访问  
                visit[i]=1;//该结点访问过标记  
                if(sum==S) return top;//如果成功，返回top，top为数组元素的个数，有所有物品的编号  
                break;  
            }  
        }  
        //如果检索到最后，也就是说栈顶前面的物品都不符合条件  
        //因此可能栈内的元素有问题，所以弹出栈顶元素，不把栈顶元素计算在内  
        if(i==n)  
        {  
            visit[q[top]]=0;//把栈顶元素定义成未访问  
            sum-=w[q[top]];//从和中减去站定物品编号的重量  
            begin=q[top]+1;//从栈顶元素的下一个物品开始检索  
            //cout<<"------"<<begin<<endl;  
            top--;//栈递减一个单位  
        }  
    }  
}  
 
int main()  
{  
    cin>>n>>S;  
    for(int i=0;i<n;i++)  
    {  
        cin>>w[i];  
        visit[i]=0;  
    }  
    int t=beibao();   
    if(t!=-1)  
    {  
        for(int i=0;i<=t;i++)  
            cout<<w[q[i]]<<" ";  
        cout<<endl;  
    }  
    else cout<<-1<<endl;  
}  
