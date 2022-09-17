#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
using namespace std;
const int maxn = 20005;
int n;
vector<int> G[maxn];
vector<int> sz(maxn,1);
vector<int> dp(maxn,0);

void dfs(int now , int lst){
	for(int &to : G[now]){
		if(to == lst) continue;
		dfs(to , now);
		sz[now] += sz[to];
		dp[now] += (n-sz[to]-1) * (sz[to]);
	}
	dp[now] += (n - sz[now]) * (sz[now] - 1);
};

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i=1 ; i<n ; ++i){
		int a,b; cin >> a >> b ;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}


	dfs(1,1);

	auto it = max_element(dp.begin() , dp.end());
	cout << it-dp.begin() << ' ' << *it/2 << '\n';
}