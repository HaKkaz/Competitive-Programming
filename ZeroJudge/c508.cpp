#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
signed main(){
	IOS;
	int n;
	while(cin >> n){
		vector<int> v(n);
		for(int &x : v) cin >> x;
		sort(all(v)) ;
		for(int &x : v) cout << x << ' ';
		endl
		v.resize(unique(all(v))-v.begin()) , sort(all(v) , greater<int>());
		for(int &x : v) cout << x << ' ';
			endl
	}
}