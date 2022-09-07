#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
int n, p, s, go, en;
int sieve[505] = {};
vector<int> v;
vector<int> vs;
 
void sangEthos(){
	sieve[0] = sieve[1] = 1;
	for(int i = 2; i < 23; i++){
		if(sieve[i] == 0)
		for(int j = i * i; j < 502; j += i)
			sieve[j] = 1;
	}
	vs.push_back(0);
	for(int i = 2; i <= 500; i++)
		if(sieve[i] == 0) vs.push_back(i);
}
void print(){
	for(int i = 1; i < v.size(); i++){
		cout << v[i] << " ";
	}
    cout << endl;
}
 
void Try(int i, int sum, int cnt = 0){
	if(sum > s) return;
	if(sum == s and cnt == n){
		print();
		return;
	}
	for(int j = go; j <= en; j++){
		if(vs[j] > v.back()){
            v.push_back(vs[j]);
            Try(i + 1, sum + vs[j], cnt + 1);
            v.pop_back();
        }
	}
}
 
 
int main (){
    faster();
    sangEthos();
	int t; cin >> t;
    int idx = 1;
	while(idx <= t){
        cout << "Test " << idx << ":" << endl;
        idx++;
		cin >> n >> p >> s;
        v.clear();
        v.push_back(0);
		go = upper_bound(vs.begin(), vs.end(), p) - vs.begin();
		en = upper_bound(vs.begin(), vs.end(), s - 1) - vs.begin() - 1;
		int sum = 0;
		Try(1, sum);
	}
}