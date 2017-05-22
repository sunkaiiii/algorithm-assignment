#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <string>  
using namespace std;  
const int maxsize=100;  
int n,S;//n���ж�������Ʒ��S��Ҫ���������  
bool visit[maxsize];//����Ƿ񱻷��ʹ�������ʹ����Ϊ1��û�з��ʹ�Ϊ0  
int w[maxsize];//��¼ÿһ����Ʒ������  
int q[maxsize];//�൱��һ��ջ���洢�����ʹ�����Ʒ�ı��  
int beibao()  
{  
    int top=-1,begin=0,sum=0;  
    int i;  
    while(top!=-2)  
    {  
        //�ӵ�һ����Ʒ��ʼѭ��  
        for(i=begin;i<n;i++)  
        {  
            //���û�б����ʹ������Ҽ�������֮��С��S  
            if(!visit[i] && w[i]+sum<=S)  
            {  
                sum+=w[i];//��sum�ϼ��ϵ�ǰ��Ʒ������  
                q[++top]=i;//����Ʒ�ı�Ŵ���q[]��  
                begin=0;//��ͷ��ʼ����  
                visit[i]=1;//�ý����ʹ����  
                if(sum==S) return top;//����ɹ�������top��topΪ����Ԫ�صĸ�������������Ʒ�ı��  
                break;  
            }  
        }  
        //������������Ҳ����˵ջ��ǰ�����Ʒ������������  
        //��˿���ջ�ڵ�Ԫ�������⣬���Ե���ջ��Ԫ�أ�����ջ��Ԫ�ؼ�������  
        if(i==n)  
        {  
            visit[q[top]]=0;//��ջ��Ԫ�ض����δ����  
            sum-=w[q[top]];//�Ӻ��м�ȥվ����Ʒ��ŵ�����  
            begin=q[top]+1;//��ջ��Ԫ�ص���һ����Ʒ��ʼ����  
            //cout<<"------"<<begin<<endl;  
            top--;//ջ�ݼ�һ����λ  
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
