#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <time.h>
#include <stdlib.h> 
#include<windows.h>
using namespace std;
int MaxSize = 10000;
typedef struct {
	int *r = new int[MaxSize + 5];
	int length;
}SqList;
void swap(SqList &L, int i, int j)
{
	int temp = L.r[i];
	L.r[i] = L.r[j];
	L.r[j] = temp;
}
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, p;
	for (j = m + 1, k = i; i <= m&&j <= n; ++k)
	{
		if (SR[i] < SR[j]) {
			TR[k] = SR[i];
			i++;
		}
		else {
			TR[k] = SR[j];
			j++;
		}
	}
	if (i <= m)
	{
		for (; i <= m; i++)
		{
			TR[k] = SR[i];
			k++;
		}
	}
	if (j <= n)
	{
		for (; j <= n; j++) {
			TR[k] = SR[j];
			k++;
		}
	}
}
void MSort(int SR[], int TR1[], int s, int t)
{
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		int m = (s + t) / 2;
		int *TR2 = new int[MaxSize + 5];
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
		delete TR2;
	}
}
void MergeSort(SqList &L)
{
	MSort(L.r, L.r, 1, L.length);
}
int Partition(SqList &L, int low, int high)
{
	int pivotKey = L.r[low];
	while (low < high)
	{
		while (low < high&&L.r[high] >= pivotKey)
			--high;
		swap(L, low, high);
		while (low < high&&L.r[low] <= pivotKey)
			++low;
		swap(L, low, high);
	}
	return low;
}
void Qsort(SqList &L, int low, int high)
{
	if (low < high)
	{
		if (low < high)
		{
			int pivot = Partition(L, low, high);
			Qsort(L, low, pivot - 1);
			Qsort(L, pivot + 1, high);
		}
	}
}
void QuickSort(SqList &L)
{
	Qsort(L, 1, L.length);
}
void getTime()
{
	time_t t = time(0);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z", localtime(&t));
	puts(tmp);
}
void sortNumber()
{
	MaxSize = 10000;
	for (int count = 0; count < 2; count++)
	{
		if (count == 1)
			MaxSize = 100000;
		cout << "���ڽ���" << MaxSize / 10000 << "�����ֵ�����..." << endl;
		Sleep(1000);
		SqList t[5];
		SqList Qsort;
		SqList Merge;
		srand((unsigned)time(NULL));
		for (int i2 = 0; i2 < 5; i2++)
		{
			for (int i = 1; i < MaxSize; i++)
			{
				t[i2].r[i] = rand();
			}
			t[i2].length = MaxSize - 1;
		}
		for (int i3 = 0; i3 < 5; i3++)
		{
			cout << "��ʼִ�е�" << i3 + 1 << "�ο������򡭡�" << endl;
			Qsort = t[i3];
			cout << "����ǰ" << endl;
			/*for (int i = 1; i<MaxSize; i++)
			{
			cout << Qsort.r[i] << ",";
			}*/
			getTime();
			QuickSort(Qsort);
			cout << endl << "�����" << endl;
			getTime();
			/*for (int i = 1; i<MaxSize; i++)
			{
			cout << Qsort.r[i] << ",";
			}*/
			//delete Qsort.r;
			cout << endl;
			for (int i = 1; i < MaxSize; i++)
			{
				t[i3].r[i] = rand();
			}
			Sleep(1000);
			Merge = t[i3];
			cout << endl << "��ʼִ�е�" << i3 + 1 << "�ι鲢���򡭡�" << endl;
			cout << "����ǰ" << endl;
			getTime();
			/*for (int i = 1; i<MaxSize; i++)
			{
			cout << Merge.r[i] << ",";
			}
			*/
			MergeSort(Merge);
			cout << endl << "�����" << endl;
			getTime();
			/*for (int i = 1; i<MaxSize; i++)
			{
			cout << Merge.r[i] << ",";
			}*/
			cout << endl;
			//delete Qsort.r;
			//delete Merge.r;
			delete t[i3].r;
			Sleep(1000);
		}
		Sleep(500);
		cout << "----------------------------------------------------\n";
		Sleep(500);
		cout << "----------------------------------------------------\n";
		Sleep(500);
		cout << "----------------------------------------------------\n";
	}
}
void Select()
{
	int n, k;
	cout << "�����뼸����\n";
	cin >> n;
	cout << "������Ҫ���ҵڼ�С����\n";
	cin >> k;
	k;
	MaxSize = n+1;
	SqList sort;
	sort.length = MaxSize - 1;
	cout << "��������������\n";
	for (int i = 1; i < MaxSize; i++)
	{
		cin >> sort.r[i];
	}
	QuickSort(sort);
	cout << "��" << k << "С��������" << sort.r[k] << endl;
	delete sort.r;
	
}
int main()
{
	char a;
	cout << "1.1��/10����������\n2.ѡ������\n";
	a = getchar();
	if(a=='1')
		sortNumber();
	if (a == '2')
		Select();
}

