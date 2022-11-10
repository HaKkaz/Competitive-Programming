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
const int maxn = 15;
vector<int> v[maxn];
bitset<maxn> vis;
void dfs(int now){
	vis[now] = 1;
	for(int &c : v[now])
		if(!vis[c])
			dfs(c);
}
signed main(){
	IOS;
	int n , m ;cin >> n >> m ;
	while(m--){
		int a,b; cin >> a >> b;
		v[a].pb(b) , v[b].pb(a);
	}
	int ans=0;
	for(int i=1 ; i<=n ; ++i) if(!vis[i]) dfs(i) , ++ans;
	cout << ans << '\n';
}