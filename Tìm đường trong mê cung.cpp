#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define endl '\n'
 
int check = 0;
int n; 
int arr[15][15] = {};
vector<string> vs;
string s = "";
void Try(int i, int j){
	if(i == n) return;
	if(j == n) return;
	if(i == n - 1 and j == n - 1) {
        check = 1;
        vs.push_back(s);
    }
	if(arr[i + 1][j] == 1) {
        s.push_back('D');
        Try(i + 1, j);
        s.pop_back();
    }
	if(arr[i][j + 1] == 1){
        s.push_back('R');
        Try(i, j + 1);
        s.pop_back();
        }
	if(arr[i + 1][j] == 0 and arr[i][j + 1] == 0)return;
}
 
int main (){
    faster();
	int t; cin >> t;
	while(t--){
		cin >> n;
        vs.clear();
        s.clear();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) cin >> arr[i][j];
		check = 0;
		if(arr[0][0] == 1 and arr[n - 1][n - 1] == 1){
			Try(0,0);
		}
        if(check == 0) cout << -1 << endl;
        else{
            sort(vs.begin(), vs.end());
            for(auto i : vs) cout << i << " ";
            cout << endl;
        }
	}
}