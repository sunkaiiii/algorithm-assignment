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

/*�ӱ��е���231�� 
Ϊ�����ҵ�һ�ֽⷨ���ڲο��������ȷ��*/ 
class AnswerWay
{
public:
    AnswerWay *parent;//ָ���׽��
    bool way;//����߽��뻹���ұ߽���
};
 
class Node
{
 
public:
    //�Ƚ����ȼ�
    operator float () const
    {
        return priority;
    }
    float priority;//�������ȼ�
    int nowValue;//��ǰ���ļ�ֵ
    int nowWeight;//��ǰ����
    int level;//��ǰ�Ĳ���
    AnswerWay *answer;//���·��
};
 
class Package
{
 
public:
    void getMaxValue();//��ȡ���ֵ
    void init();
private:
    void addPriorityQueue(float, int, int, int, bool);//�������ȶ���
    float bound(int);//�����ֵ�Ͻ�
    int maxValue();//�����Ŀ���������ֵ
    void sort();//����Ʒ��λ��ֵ��������
    //��package�ĸ������Խ��г�ʼ��
    void destructor();//����new�����Ŀռ�
    void getError()//���Դ���,��ɾ��
    {
        for(int i = 0; i <= n; i++)
            cout<<"value = "<<value[i]<<" weight = "<<weight[i]<<endl;
    }
private:
    int packageWeight;//����������
//    int n;//��Ʒ������
    int* weight;//ÿ����Ʒ������
    int* value;//ÿ����Ʒ�ļ�ֵ
    int nowWeight;//�����ĵ�ǰ����
    int nowValue;//�����ĵ�ǰ��ֵ
    int level;//��ǰ���
    priority_queue<Node> prQueue;//���ȶ���
    AnswerWay *answer;//���·��
    bool* bestWay;//���Ž�
};
 
/*���new�����Ŀռ�*/
void Package::destructor()
{
    delete[] weight;
    delete[] value;
    delete[] bestWay;
}
 
//���⺯������ȡ������������ֵ
void Package::getMaxValue()
{
    init();
    sort();
    //��ȡ����ֵ
    cout<<"���������ɵ�����ֵΪ: "<<maxValue()<<endl;
    //��ȡ���Ž�
//    cout<<"���Ž�Ϊ: "<<endl;
//    for(int i = 1; i <= n; i++)
//        if(bestWay[i])
//            cout<<"weight = "<<weight[i]<<" value = "<<value[i]<<endl;
    destructor();
}
 
/*���㱳��������ֵ*/
int Package::maxValue()
{
    /*����Ҫ��������wt����*/
    int bestValue = 0;//��ǰ����ֵ
    float priority = bound(1);//��ֵ�Ͻ磬Ҳ���ǽ�Ҫ�������ȶ����е����ȼ�
    Node node = Node();//���Ӧ�������涨��
 
    while(level != (n+1))
    {
        if((nowWeight+weight[level]) <= packageWeight)
        {
            if((nowValue+value[level]) > bestValue)
                bestValue = nowValue + value[level];
            //����ӵļ�ֵ�Ͻ��ǰ����˸ý���
            addPriorityQueue(priority, nowValue+value[level], nowWeight+weight[level], level+1, true);
        }
        //level+1����Ϊ��һ�����Ʒû�зŽ����������Ҷ�����˵��ʣ���ֵ���Ǵ�level+1��ʼ
        priority = bound(level+1);
        if(priority >= bestValue)
            addPriorityQueue(priority, nowValue, nowWeight, level+1, false);
 
        /*�����ȶ����л�ȡ�����ȼ���ߵ�Ԫ��*/
        node = prQueue.top();
        prQueue.pop();
        /*���µ�ǰ��������ֵ*/
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
 
/*����Ʒ��λ��ֵ��������*/
void Package::sort()
{
    float tempUnitValue;//��ʱ��λ��ֵ
    int tempValue;//��ʱ��ֵ
    int tempWeight;//��ʱ����
 
    float *unitValue = new float[n+1];//��Ʒ�ĵ�λ��ֵ
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
 
/*��package�ĸ������Խ��г�ʼ��*/
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
 
/*�������ȶ��У�����priority,nowValue,nowWeight,level��ͬ��Package���е�����*/
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
 
/*���ֵ�Ͻ磨�Ӹ��ڵ�ļ�ֵ����ǰ���ļ�ֵ�ټ���ʣ���ֵ�������������ȶ���Ʒ�ĵ�λ��ֵ�Ӵ�С����*/
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
/*��Ϊ���ϴ����ڲο��������ȷ��*/ 


/*��ǰʵ�����õĴ�ͳ�ݹ����*/ 
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
    strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A ±¾ÄêµÚ%jÌì %z", localtime(&t));
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
		cout<<"��֧�޽�"<<zuiyoujiazhi<<','<<zuiyourongliang<<endl; 
//        getTime();  
        zong=0;
        zongc=0;
//        getTime();
        f(v,w,n,0,c,0,0,take);
        cout<<"��ͨ�ݹ�"<<"v:"<<zong<<",c:"<<zongc<<endl<<endl<<endl;
//        getTime();
        zong=0;
        zongc=0;
        cout<<endl;
//        getTime();
        backTrace(); 
        cout<<"��ͨ���ݷǵݹ�"<<"v:"<<zong<<",c:"<<zongc<<endl<<endl<<endl;
//        getTime();
		cout<<endl;

    }
    // for (int i2 = 0; i2 < 5; i2++)
    // {

    // }
}
