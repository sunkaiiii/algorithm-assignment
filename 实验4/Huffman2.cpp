#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXVALUE 200           
#define MAXBIT  30            
#define MAXNODE 30             
struct haffnode
{
	char data;
	int weight;
	int flag;			
	int parent;       
	int leftchild;    
	int rightchild;   
};

struct haffcode
{
	int bit[MAXNODE];
	int start;     
	char data;
	int weight;     
};

void haffmantree(int weight[], int n, struct haffnode hafftree[], char data[])//建立霍夫曼树 ，并传入用户输入然后初始化树 
{
	int i, j, m1, m2, x1, x2;
	for (i = 0; i<2 * n - 1; i++)
	{
		if (i<n)
		{
			hafftree[i].data = data[i];
			hafftree[i].weight = weight[i];  
		}
		else
		{
			hafftree[i].weight = 0;         
			hafftree[i].data = '\0';
		}
		hafftree[i].parent = 0;                   
		hafftree[i].flag = 0;
		hafftree[i].leftchild = -1;
		hafftree[i].rightchild = -1;
	}
	for (i = 0; i<n - 1; i++)                          
	{
		m1 = m2 = MAXVALUE;
		x1 = x2 = 0;
		for (j = 0; j<n + i; j++)
		{
			if (hafftree[j].weight<m1&&hafftree[j].flag == 0)//根据传入的参数，对于原始树的结构进行重新构建 
			{
				m2 = m1;
				x2 = x1;
				m1 = hafftree[j].weight;
				x1 = j;
			}
			else if (hafftree[j].weight<m2&&hafftree[j].flag == 0)
			{
				m2 = hafftree[j].weight;
				x2 = j;
			}
		}
		hafftree[x1].parent = n + i;
		hafftree[x2].parent = n + i;
		hafftree[x1].flag = 1;
		hafftree[x2].flag = 1;
		hafftree[n + i].weight = hafftree[x1].weight + hafftree[x2].weight;
		hafftree[n + i].leftchild = x1;
		hafftree[n + i].rightchild = x2;
	}
}

void haffmancode(struct haffnode hafftree[], int n, struct haffcode haffcode[])
{
	int i, j, child, parent;
	struct haffcode newcode;
	struct haffcode *cd;
	cd = &newcode;
	for (i = 0; i<n; i++)//将节点的父节点和子节点进行规定 
	{
		cd->start = MAXBIT - 1;                         
		cd->weight = hafftree[i].weight;
		cd->data = hafftree[i].data;    
		child = i;
		parent = hafftree[child].parent;
		while (parent != 0)
		{
			if (hafftree[parent].leftchild == child)
				cd->bit[cd->start] = 0;                        
			else
				cd->bit[cd->start] = 1;                        
			cd->start--;
			child = parent;
			parent = hafftree[child].parent;
		}
		for (j = cd->start + 1; j<MAXBIT; j++)    
			haffcode[i].bit[j] = cd->bit[j];
		haffcode[i].data = cd->data;
		haffcode[i].start = cd->start;
		haffcode[i].weight = cd->weight;
	}
}

void pprintf(struct haffcode myhaffcode[], int n)//将哈弗曼书中的每个节点按顺序输出 
{
	int i, j, count = 0;
	for (i = 0; i<n; i++)
	{
		printf("字符=%c", myhaffcode[i].data);
		printf("              ");
		printf("weight=%3d", myhaffcode[i].weight);
		printf("              ");
		printf("haffcode=");
		for (j = myhaffcode[i].start + 1; j<MAXBIT; j++)
			printf("%d", myhaffcode[i].bit[j]);
		printf("\n");
		count++;
	}
}
void StringToBIt(struct haffcode myhaffcode[], char a)//用于将用户输入的字符串转换为哈弗曼编码编程的一串编码 
{
	int i, j, count = 0;
	for (i = 0;i<MAXVALUE; i++)
	{
		if (myhaffcode[i].data == a)
		{
			for (j = myhaffcode[i].start + 1; j < MAXBIT; j++)
				printf("%d", myhaffcode[i].bit[j]);
			break;
		}
	}
}
int main()
{
	int n;
	char ch;
	printf("多少个字符?\n");
	scanf("%d",&n);
	printf("请输入字符,权重\n");
	int weight[1000];
	char data[1000];
	getchar(); //用于消除回车引发的输入问题 ，下面的getchar()作用一样 
	for(int i=0;i<n;i++)
	{
		scanf("%c,%d",&data[i],&weight[i]);
		getchar();
	}
	struct haffnode newhaffnode[2 * MAXNODE - 1];
	struct haffcode newcode[MAXNODE];
	struct haffnode *myhafftree = newhaffnode;
	struct haffcode *myhaffcode = newcode;
	printf("对所有的字符编码");
	printf("\n");
	haffmantree(weight, n, myhafftree, data);
	haffmancode(myhafftree, n, myhaffcode);
	pprintf(myhaffcode, n);
	printf("\n");
}

