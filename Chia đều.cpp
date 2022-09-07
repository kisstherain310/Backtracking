#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
int n, k, arr[20] = {}, sum[20] = {}; 
int x;
 
int dem = 0;
void Try(int i, int cnt = 0){
	if(cnt > k) return;
	if(cnt == k and i == n + 1) {
        dem++;
    }
	for(int j = i; j <= n; j++){
		if(sum[j] - sum[i] + arr[i] == x){
			Try(j + 1, cnt + 1);
		}
	}
}
 
int main (){
    faster();
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		dem = 0;
		x = sum[n] / k;
		if(sum[n] % k == 0) Try(1);
		cout << dem << endl;
	}
}