#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define ft first
#define sd second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int maxn = 100050;
vector< pii > v[maxn];
int sz[maxn] , bike[maxn] , ans;
int a[maxn];
int n , k;

void dfs(int now , int fa , int weight){
	bike[now] = a[now];
	sz[now] = 1;

	for(auto &nxt : v[now]){
		if(nxt.ft != fa){
			dfs(nxt.ft , now , nxt.sd);
			sz[now] += sz[nxt.ft];
			bike[now] += bike[nxt.ft]; 
		}
	}
	if(bike[now] != k * sz[now]){
		ans += abs(bike[now] - k*sz[now]) *  weight;
	}
}

signed main(){
	IOS;
	cin >> n >> k ;
	for(int i=1 ; i<=n ; ++i) cin >> a[i];
	for(int i=1 ; i<n ; ++i){
		int a,b,w; cin >> a >> b >> w;
		v[a].emplace_back(b,w);
		v[b].emplace_back(a,w);
	}
	dfs(1 , -1 , 0);
	cout << ans << '\n';
}