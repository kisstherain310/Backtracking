#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
int n, k, check = 0;
int arr[20] = {};
int kq[20] ={};
 
bool cmp(int a, int b){
	return a > b;
}
 
void print(int i){
	cout << "(";
	for(int j = 1; j < i; j++)
		cout << kq[j] << " ";
	cout << kq[i] << ")" << " ";
}
 
void Try(int i, int sum){
	if(sum > n) return;
	if(sum == n){
		print(i - 1);
        check = 1;
		return;
	}
	else{
		for(int j = 1; j <= n; j++){
			if(arr[j] <= kq[i - 1]){
                kq[i] = arr[j];
			    Try(i + 1, sum + kq[i]);
            }
		}
	}
}
 
int main (){
    faster();
	int t; cin >> t;
	while(t--){
        arr[20] = {};
        kq[20] ={}, check = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) arr[i] = i;
			sort(arr + 1, arr + n + 1, cmp);
		int sum = 0;
        kq[0] = n;
		Try(1, sum);
        if(check == 0) cout << "-1";
        cout << endl;
	}
}