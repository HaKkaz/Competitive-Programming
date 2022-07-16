#pragma GCC optimize("Ofast", "unroll-loops", "fast-math" , "O2")
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

const int maxn = 3e5+50;
vector< pii > G[maxn];
array<array<int,2> , maxn> dp;
array<int,maxn> d;

void dfs(int now , int lst , int cost){
	dp[now][0] = 0;
	dp[now][1] = d[now] ? cost : -1e18;

	vector<int> dps;
	for(auto &[nxt,w] : G[now]){
		if(nxt == lst) continue;
		dfs(nxt , now , w);
		dps.emplace_back(dp[nxt][1]-dp[nxt][0]);
		dp[now][0] += dp[nxt][0];
		dp[now][1] += dp[nxt][0];
	}

	sort(ALL(dps),greater<int>());

	for(int i=0 ; i<(int)dps.size() ; ++i){
		//no select
		if(i < d[now] && dps[i] > 0) dp[now][0] += dps[i];

		//select
		if(i < d[now]-1 && dps[i] > 0) dp[now][1] += dps[i];
	}
}

signed main(){
	fast;
	int t=1;
	// cin >> t;
	while(t--){
		int n; cin >> n ;
		for(int i=1 ; i<=n ; ++i) cin >> d[i];

		for(int i=1 ; i<n ; ++i){
			int a,b,w;
			cin >> a >> b >> w;
			G[a].emplace_back(b,w);
			G[b].emplace_back(a,w);
		}

		dfs(1 , 1 , 0);

		cout << *max_element(ALL(dp[1])) << '\n';
	}
}