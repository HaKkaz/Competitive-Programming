#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
struct KMP{
	vector<int> f;
	string T , P;
	void build(){
		const int n = T.size();
		f.resize(n);
		f[0]=-1;
		for(int i=1,fp=-1 ; i<n ; ++i){
			while(~fp && T[i] != T[fp+1]){
				fp = f[fp];
			}
			if(T[i] == T[fp+1]) ++fp;
			f[i] = fp;
		}
	}
	int matching(){
		int res=0;
		const int n = T.size();
		for(int i=0,fp=-1 ; i<sz(P) ; ++i){
			while(~fp && P[i] != T[fp+1]){
				fp = f[fp];
			}
			if(P[i] == T[fp+1]) ++fp;
			if(fp == n-1) ++res , fp = f[fp];
		}
		return res;
	}
}A;
signed main(){
	IOS;
	int n; cin >> n;
	cin >> A.T >> A.P;
	A.build();
	int cnt = A.matching();
	// cout << cnt << '\n';
	if(cnt == n) cout << "YES\n";
	else cout << "NO\n";
}