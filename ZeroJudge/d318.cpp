#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3","unroll-loops")
#define int long long
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
signed main(){
//__IO
	int n;
	while(cin >> n && n>=0){
		vector<int> v;
		if(n==0){
			cout << 0 << '\n';
			continue;
		}
		while(n){
			v.pb(n%3);
			n/=3;
		}
		reverse(all(v));
		for(auto &c : v) cout << c;
		puts("");
	}	
}