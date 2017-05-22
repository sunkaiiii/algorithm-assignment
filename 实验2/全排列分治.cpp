#include <cstring>
#include <iostream>
using namespace std;
char str[1000];
void Perm(char *str, int k, int m);
void Swap(char &a, char &b);
int main()
{
	cout << "¼¸¸öÊı×Ö£¿\n";
	int n;
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		int a;
		cin >> a;
		str[i] = a + '0';
	}
	Perm(str, 1, n);
	return 0;
} 
void Perm(char *str, int k, int m)
{
        int i;
        if(k == m)
        {
                for(i=1; i<=m; ++i)
                        cout<<str[i]<<" "<<flush;
                cout<<endl;
                return;
        }
 
        for(i=k; i<=m; ++i)
        {
                Swap(str[k], str[i]);
                Perm(str, k+1, m);
                Swap(str[k], str[i]);
        }
 
}
void Swap(char &a, char &b)
{
        char tmp = a;
        a = b;
        b = tmp;
}