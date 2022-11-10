#include"bits/stdc++.h"
#define pb push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 100005;
vector<int> E[maxn];
int mp[maxn] , ans , p , q , k , t;
bitset<100005> vis;
bool dfs(int x){
	vis[x] = 1;
	for(auto &i : E[x])
		if(!mp[i] or (!vis[mp[i]] and dfs(mp[i])))
			return mp[i] = x , 1;
	return 0;
}
inline void init(){
	ans = 0;
	for(int i=1 ; i<=p ; ++i) E[i].clear();
	for(int i=1 ; i<=q ; ++i) mp[i] = 0;
}
inline void latina(){
	cin >> t;
	while(t--){
		cin >> p >> q >> k;
		init();
		for(int i=0 ; i<k ; ++i){
			int a , b; cin >> a >> b;
			E[a].pb(b);
		}

		for(int i=1 ; i<=p ; ++i){
			if(vis.reset() , dfs(i)) ++ans;
		}

		cout << ans << '\n';
	}
}
signed main(){loli;latina();}