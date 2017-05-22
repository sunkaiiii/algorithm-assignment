#include    <iostream>
#include    <cstring>
#include    <time.h>
#include    <stdlib.h>
#include    <queue>
using namespace std;
int zong,zongc;
int take[1000];
int shengyujiazhi=0;
int dangqianjiazhi=0;
int dangqianrongliang=0;
int zuiyourongliang=0;
int zuiyoujiazhi=0;
int v[1000];
int w[1000];
int c,n;

/*从本行到第231行 
为网上找的一种解法用于参考结果的正确性*/ 
class AnswerWay
{
public:
    AnswerWay *parent;//指向父亲结点
    bool way;//是左边进入还是右边进入
};
 
class Node
{
 
public:
    //比较优先级
    operator float () const
    {
        return priority;
    }
    float priority;//结点的优先级
    int nowValue;//当前结点的价值
    int nowWeight;//当前重量
    int level;//当前的层数
    AnswerWay *answer;//结点路径
};
 
class Package
{
 
public:
    void getMaxValue();//获取最大值
    void init();
private:
    void addPriorityQueue(float, int, int, int, bool);//加入优先队列
    float bound(int);//求出价值上界
    int maxValue();//背包的可容纳最大价值
    void sort();//对物品单位价值进行排序
    //对package的各个属性进行初始化
    void destructor();//清理new产生的空间
    void getError()//测试错误,可删除
    {
        for(int i = 0; i <= n; i++)
            cout<<"value = "<<value[i]<<" weight = "<<weight[i]<<endl;
    }
private:
    int packageWeight;//背包的重量
//    int n;//物品的总数
    int* weight;//每个物品的重量
    int* value;//每个物品的价值
    int nowWeight;//背包的当前重量
    int nowValue;//背包的当前价值
    int level;//当前层次
    priority_queue<Node> prQueue;//优先队列
    AnswerWay *answer;//结点路径
    bool* bestWay;//最优解
};
 
/*清除new产生的空间*/
void Package::destructor()
{
    delete[] weight;
    delete[] value;
    delete[] bestWay;
}
 
//对外函数，获取到背包的最优值
void Package::getMaxValue()
{
    init();
    sort();
    //获取最优值
    cout<<"背包可容纳的最优值为: "<<maxValue()<<endl;
    //获取最优解
//    cout<<"最优解为: "<<endl;
//    for(int i = 1; i <= n; i++)
//        if(bestWay[i])
//            cout<<"weight = "<<weight[i]<<" value = "<<value[i]<<endl;
    destructor();
}
 
/*计算背包的最优值*/
int Package::maxValue()
{
    /*不需要定义书中wt变量*/
    int bestValue = 0;//当前最优值
    float priority = bound(1);//价值上界，也就是将要加入优先队列中的优先级
    Node node = Node();//结点应放在外面定义
 
    while(level != (n+1))
    {
        if((nowWeight+weight[level]) <= packageWeight)
        {
            if((nowValue+value[level]) > bestValue)
                bestValue = nowValue + value[level];
            //左儿子的价值上界是包括了该结点的
            addPriorityQueue(priority, nowValue+value[level], nowWeight+weight[level], level+1, true);
        }
        //level+1是因为这一层的物品没有放进背包，对右儿子来说，剩余价值就是从level+1开始
        priority = bound(level+1);
        if(priority >= bestValue)
            addPriorityQueue(priority, nowValue, nowWeight, level+1, false);
 
        /*从优先队列中获取到优先级最高的元素*/
        node = prQueue.top();
        prQueue.pop();
        /*更新当前各个属性值*/
        nowWeight = node.nowWeight;
        nowValue = node.nowValue;
        priority = node.priority;
        answer = node.answer;
        level = node.level;
    }
 
    for(int i = n; i > 0; i--)
    {
        bestWay[i] = answer->way;
        answer = answer->parent;
    }
 
    return bestValue;
}
 
/*对物品单位价值进行排序*/
void Package::sort()
{
    float tempUnitValue;//临时单位价值
    int tempValue;//临时价值
    int tempWeight;//临时重量
 
    float *unitValue = new float[n+1];//物品的单位价值
    unitValue[0] = 0;
    for(int i = 1; i <= n; i++)
        unitValue[i] = float(value[i])/float(weight[i]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(unitValue[i] < unitValue[j])
            {
                tempUnitValue = unitValue[i];
                unitValue[i] = unitValue[j];
                unitValue[j] = tempUnitValue;
 
                tempValue = value[i];
                value[i] = value[j];
                value[j] = tempValue;
 
                tempWeight = weight[i];
                weight[i] = weight[j];
                weight[j] = tempWeight;
            }
        }
    }
    delete[] unitValue;
}
 
/*对package的各个属性进行初始化*/
void Package::init()
{
	weight = new int[n+1];
	weight[0] = 0;
	packageWeight=c;
    for(int i = 0; i < n; i++)
    {
//    	cout<<"24124214";
        weight[i+1]=w[i];

    }

    value = new int[n+1];
    value[0] = 0;
    for(int i = 0; i < n; i++){
        value[i+1]=v[i];
    }
    nowValue = 0;
    nowWeight = 0;
    level = 1;
    answer = 0;
    bestWay = new bool[n+1];
    for(int i = 0; i <= n; i++)
        bestWay[i] = false;
}
 
/*加入优先队列，参数priority,nowValue,nowWeight,level不同于Package类中的属性*/
void Package::addPriorityQueue(float priority, int nowValue, int nowWeight, int level, bool ch)
{
    AnswerWay *answerTemp = new AnswerWay;
    answerTemp->parent = answer;
    answerTemp->way = ch;
 
    Node node = Node();
    node.priority = priority;
    node.nowValue = nowValue;
    node.nowWeight = nowWeight;
    node.level = level;
    node.answer = answerTemp;
    prQueue.push(node);
}
 
/*求价值上界（从根节点的价值到当前结点的价值再加上剩余价值）函数，必须先对物品的单位价值从大到小排序*/
float Package::bound(int tempLevel)
{
    int leftPackageWeight = packageWeight - nowWeight;
    float priority = nowValue;
    while(tempLevel <= n && weight[tempLevel] <= leftPackageWeight)
    {
        leftPackageWeight -= weight[tempLevel];
        priority += value[tempLevel];
        tempLevel++;
    }
    if(tempLevel <= n)
        priority += (value[tempLevel]*0.1)/(weight[tempLevel]*0.1)*leftPackageWeight;
    return priority;
}
/*此为网上答案用于参考结果的正确性*/ 


/*以前实验所用的传统递归回溯*/ 
void f(int v[],int w[],int n,int position,int c,int value,int rongliang,int take[])
{
    // for(int i=0;i<n;i++)
    // {
    //  if(take[i]==0&&take[position]==0)
    //      cout<<i<<',';
    // }
    if(position==n)
    {
        if(zong<value)
        {
            zong=value;
            zongc=rongliang;
            return;
        }
        return;
    }
    if(rongliang+w[position]<=c)
    {
        value+=v[position];
        rongliang+=w[position];
        take[position]=1;
        f(v,w,n,position+1,c,value,rongliang,take);
        value-=v[position];
        rongliang-=w[position];
        // for(int i=0;i<n;i++)
        // {
        //  if(take[i]==0&&take[position]==1)
        //      cout<<i<<',';
        // }
        // cout<<endl;
        take[position]=0;
        f(v,w,n,position+1,c,value,rongliang,take);
    }
    else
    {
        if(zong<value)
        {
            zong=value;
            zongc=rongliang;
            return;
        }
        return;
    }
}

void getTime()
{
    time_t t = time(0);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A 卤戮脛锚碌脷%j脤矛 %z", localtime(&t));
    puts(tmp);
}

class T{
public:
    int v,w;
    double quanzhong;
    T(int v1,int w1,double bizhi):v(v1),w(w1),quanzhong(bizhi){}
};

bool operator >(const T &t1, const T &t2)
{
    return t1.quanzhong>t2.quanzhong;
}
bool operator <(const T &t1, const T &t2)
{
    return t1.quanzhong<t2.quanzhong;
}


priority_queue<T> q;


void f_jiexian(int level)
{
    if(q.empty())
    {
    	if(zuiyoujiazhi<dangqianjiazhi)
	    {
	        zuiyourongliang=dangqianrongliang;
	        zuiyoujiazhi=dangqianjiazhi;
	    }
        return; 
    }
    T t=q.top();
    q.pop();
    shengyujiazhi-=t.v;
    // cout<<t.v<<","<<t.w<<","<<t.quanzhong<<endl;
    if(shengyujiazhi+dangqianjiazhi+t.v>=zuiyoujiazhi)
    {
		if(dangqianrongliang+t.w<=c)
		{
	        dangqianrongliang+=t.w;
	        dangqianjiazhi+=t.v;
	        if(zuiyoujiazhi<dangqianjiazhi)
	        {
	            zuiyourongliang=dangqianrongliang;
	            zuiyoujiazhi=dangqianjiazhi;
	        }
	        f_jiexian(level+1);
	        dangqianrongliang-=t.w;
	        dangqianjiazhi-=t.v;
	    }
	    f_jiexian(level+1);

    }
    else
    {
    	if(zuiyoujiazhi<dangqianjiazhi)
        {
            zuiyourongliang=dangqianrongliang;
            zuiyoujiazhi=dangqianjiazhi;
        }
        return;
    }

}


void backTrace()
{
    int flag=0;
    int linshirongliang=0;
	int linshivalue=0;
	int place[1000];
	memset(place,0,sizeof(place));
    while(flag>=0)
    {
        while(flag<n)
        {
            if(linshirongliang+w[flag]<=c&&place[flag]==0)
            {
                place[flag]++;
                linshivalue+=v[flag];
                linshirongliang+=w[flag];
            }
            flag++;
        }
        if(linshivalue>=zong)
        {
            zong=linshivalue;
            zongc=linshirongliang;
        }
        if(flag>=n)
        {
            flag-=1;
        }
        while(place[flag]==0&&flag>=0)
        {
            flag--;
        }
        if(flag>=0)
        {
            place[flag]=0;
            linshirongliang-=w[flag];
            linshivalue-=v[flag];
            flag++;
        }
    }
}
int main()
{

    cout<<"duo shao rong liang\n";
    cin>>c;
    cout<<"ji zhong wu pin?\n";
    cin>>n;
    // zongc=0;
    // zong=0;
    // for(int i=0;i<n;i++)
    // {
    //  cout<<"di "<<i+1<<" ge de v\n";
    //  cin>>v[i];
    //  cout<<"di "<<i+1<<" ge de w\n";
    //  cin>>w[i];
    //  shengyujiazhi+=v[i];
    //  q.push(T(v[i],w[i],double(v[i]/double(w[i]))));
    // }

    memset(take,0,sizeof(take));
    srand((unsigned)time(NULL));
    for (int i2 = 0; i2 < 5; i2++)
    {
        shengyujiazhi=0;
        dangqianjiazhi=0;
        dangqianrongliang=0;
        zuiyourongliang=0;
        zuiyoujiazhi=0;
        zongc=0;
        zong=0;
        q=priority_queue<T>();
        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        Package package = Package();
        for (int i = 0; i < n; i++)
        {
            while(1)
            {
                v[i] = rand(); 
                if(v[i]<c/3&&v[i]>0)
                    break;
            }
            while(1)
            {
                w[i] = rand();
                if(w[i]<c/3&&w[i]>0)
                    break;
            }
            shengyujiazhi+=v[i];
            q.push(T(v[i],w[i],double(v[i]/double(w[i]))));
        }
    	package.getMaxValue();
//        getTime();
        f_jiexian(0);
        cout<<i2<<endl;
		cout<<"分支限界"<<zuiyoujiazhi<<','<<zuiyourongliang<<endl; 
//        getTime();  
        zong=0;
        zongc=0;
//        getTime();
        f(v,w,n,0,c,0,0,take);
        cout<<"普通递归"<<"v:"<<zong<<",c:"<<zongc<<endl<<endl<<endl;
//        getTime();
        zong=0;
        zongc=0;
        cout<<endl;
//        getTime();
        backTrace(); 
        cout<<"普通回溯非递归"<<"v:"<<zong<<",c:"<<zongc<<endl<<endl<<endl;
//        getTime();
		cout<<endl;

    }
    // for (int i2 = 0; i2 < 5; i2++)
    // {

    // }
}
