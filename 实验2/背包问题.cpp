#include<cstdio>  
#include<cstring>   
#include<iostream>  
#include<algorithm>  
using namespace std;
int main()
{
	int c, n;
	cout << "输入几种物品\n";
	cin >> n;
	cout << "输入背包容积\n";
	cin >> c;
	int sign[1000][100];
	int w[110], val[110];
	int dp[1010];
	memset(sign, 0, sizeof(sign));
	memset(w, 0, sizeof(w));
	memset(val, 0, sizeof(val));
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i<n; i++)
	{
		cin >> val[i];
	}
	for (int i = 0; i<n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i<n; i++)
		for (int j = c; j >= w[i]; j--)
		{
			if (dp[j] > dp[j - w[i]] + val[i])
			{
				dp[j] = dp[j];
			}
			else
			{				
				dp[j] = dp[j - w[i]] + val[i];
				sign[dp[j]][i] = 1;
				//cout << j << "," << dp[j] << endl;
			}
		}
	cout << "放入的物品是:";
	int cc = dp[c];
	while(cc>0)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (sign[cc][i] == 1)
			{
				cout << i+1 << ",";
				cc = cc - val[i];
				break;
			}
		}
	}
	cout << endl << "价值为" << dp[c] << endl;
}

