#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
using namespace std;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	const int INF = 1e9;
	const char st[]={'A','U','C','G'};
	const int maxn = 1005;
	int n,m; cin >> n >> m;

	vector< vector<int> > G(n);
	vector< string > str(n);

	int root = -1;
	for(int i=1 ; i<=n ; ++i){
		int a,b; cin >> a >> b , --a,--b;
		cin >> str[a];
		if(a == b) root = a;
		else G[b].emplace_back(a);
	}

	int ans=0;
	for(int i=0 ; i<m ; ++i){
		vector< vector<int> > dp(maxn , vector<int>(4,INF));
		vector< char > ch(n);
		for(int j=0 ; j<n ; ++j) ch[j] = str[j][i];

		function<void(int,int)> dfs;
		dfs = [&](int now , int lst){
			for(int j=0 ; j<4 ; ++j){
				if(ch[now] != '@' && ch[now] != st[j]) continue;
				dp[now][j] = 0;
			}

			for(int &to : G[now]){
				if(to == lst) continue;
				dfs(to , now);

				for(int a=0;a<4;++a){
					if(ch[now] != '@' && ch[now] != st[a]) continue;
					int val = INF;
					for(int b=0;b<4;++b){
						val = min(val , dp[to][b] + (a != b) );
					}
					dp[now][a] += val;
				}

			}
		};

		dfs(root,root);

		ans += *min_element(dp[root].begin() , dp[root].end());
	}
	cout << ans << '\n';

	
}