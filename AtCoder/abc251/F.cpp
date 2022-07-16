#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

const int maxn = 2e5+50;
vector<pii> v[maxn];
vector< pii > ans;
bitset<maxn> vis;

void dfs(int now){
	vis[now] = true;
	for(auto &[nxt , id] : v[now]){
		if(!vis[nxt]){
			ans.emplace_back(now , nxt);
			dfs(nxt);
		}
	}
}

void bfs(int now){
	vis.reset();
	queue<int> q;
	q.emplace(now);
	vis[now] = true;
	while(q.size()){
		int cur = q.front();
		q.pop();
		for(auto &[nxt , id] : v[cur]){
			if(!vis[nxt]){
				vis[nxt] = true;
				q.emplace(nxt);
				ans.emplace_back(cur , nxt);
			}
		}
	}
}

signed main(){
	fast;
	int n, m ;
	cin >> n >> m ;
	vector< pii > Edges;
	for(int i=0 ; i<m ; ++i){
		int a,b; cin >> a >> b;
		v[a].emplace_back(b,i);
		v[b].emplace_back(a,i);
		Edges.emplace_back(a,b);
	}

	dfs(1);
	bfs(1);

	for(auto [a,b] : ans) cout << a << ' ' << b << '\n';
}