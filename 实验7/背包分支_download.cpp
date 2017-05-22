#include <iostream>
#include <queue>
using namespace std;
 
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
private:
    void addPriorityQueue(float, int, int, int, bool);//�������ȶ���
    float bound(int);//�����ֵ�Ͻ�
    int maxValue();//�����Ŀ���������ֵ
    void sort();//����Ʒ��λ��ֵ��������
    void init();//��package�ĸ������Խ��г�ʼ��
    void destructor();//����new�����Ŀռ�
    void getError()//���Դ���,��ɾ��
    {
        for(int i = 0; i <= n; i++)
            cout<<"value = "<<value[i]<<" weight = "<<weight[i]<<endl;
    }
private:
    int packageWeight;//����������
    int n;//��Ʒ������
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
    cout<<"�����뱳��������: "<<endl;
    cin>>packageWeight;
    cout<<"�������ж��ٸ���Ʒ: "<<endl;
    cin>>n;
    weight = new int[n+1];
    weight[0] = 0;
    cout<<"�����������Ʒ������: "<<endl;
    for(int i = 1; i <= n; i++)
        cin>>weight[i];
    value = new int[n+1];
    value[0] = 0;
    cout<<"�����������Ʒ�ļ�ֵ: "<<endl;
    for(int i = 1; i <= n; i++)
        cin>>value[i];
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
 
int main()
{
    Package package = Package();
    package.getMaxValue();
    system("pause");
    return 0;
}
