#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'

int cnt = 0, sum = 0, n, s, min_1 = 1e+9;
int a[105];
void Try(int i, int sum, int cnt)
{
	if(i < n)
	{
		Try(i+1, sum + a[i], cnt+1);
		Try(i+1, sum, cnt);
	}
	else
	{
		if(sum == s && min_1 > cnt)	min_1 = cnt;
	}
}
 
int main(){
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		min_1 = 1e9;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		Try(0,sum,0);
		cout << min_1 << endl;
	}
}