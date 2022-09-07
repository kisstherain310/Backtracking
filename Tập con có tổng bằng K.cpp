#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
int n, S;
vector<int> v;
int arr[20] = {};
int check = 0;
 
void print(){
	cout << "[";
	for(int i = 1; i < v.size() - 1; i++) 
		cout << v[i] << " ";
	cout << v[v.size() - 1] << "] ";
}
 
void Try(int i, int sum = 0){
 
	if(sum > S) return;
	if(sum == S){
		check = 1;
		print();
		return;
	}
	//if(i > n ) return;
	for(int i = 1; i <= n; i++){
		if(arr[i] > v[v.size() - 1]){
			v.push_back(arr[i]);
			Try(i + 1, sum + arr[i]);
			v.pop_back();
		}
	}
}
 
int main(){
	faster();
	ll t; cin >> t; while(t--){
		v.clear();
		check = 0;
		v.push_back(0);
		cin >> n >> S;
		for(int i = 1; i <= n; i++) 
			cin >> arr[i];
		sort(arr + 1, arr + n + 1);
		Try(1);
		if(check == 0) cout << -1;
		cout << endl;
	}
}