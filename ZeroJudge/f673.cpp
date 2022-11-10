#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
vector<int> v[20];
int mx=0;
int dfs(int now){
	int ret=0;
	if(v[now][0] != -1) ret = max(ret , dfs(v[now][0]) + 1);
	if(v[now][1] != -1) ret = max(ret , dfs(v[now][1]) + 1);
	return ret;
}
signed main(){
	IOS;
	int n ;
	cin >> n ;
	for(int i=0 ; i<n ; ++i){
		int u,a,b;
		cin >> u >> a >> b;
		v[u].pb(a);
		v[u].pb(b);
	}
	cout << dfs(0) << '\n';
}