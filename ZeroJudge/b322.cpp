#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define endl cout<<'\n';
using namespace std;
const int maxn = 40000;
vector<int> E[maxn];
int ac[20][maxn] , in[maxn] , out[maxn],t,sum[maxn];
int n , m;
bitset<maxn> vis;
void dfs(int now){
	vis[now] = 1;
	in[now] = t++;
	for(auto &c : E[now])
		if(!vis[c])
			ac[0][c]=now,dfs(c);
	out[now]=t++;
}
inline bool is_ac(int a , int b){
	return(in[a]<=in[b] and out[a]>=out[b]);
}
inline void build_lca(){
	ac[0][0] = 0;
	for(int i=1 ; i<20 ; ++i){
		for(int j=0 ; j<n ; ++j)
		{
			ac[i][j] = ac[i-1][ac[i-1][j]];
		}
	}
}
inline int lca(int a , int b){
	if(is_ac(a , b)) return a;
	if(is_ac(b , a)) return b;
	for(int i=19 ; i>=0 ; --i){
		if(!is_ac(ac[i][a],b)) a = ac[i][a];
	}
	return ac[0][a];
}
void dfs2(int now){
	vis[now]=1;
	for(auto &c : E[now])
		if(!vis[c])
			dfs2(c),sum[now] += sum[c];
}
inline void init(){
	t=0;
	vis.reset();
	for(int i=0 ; i<n ; ++i) E[i].clear(),sum[i]=0;
	for(int i=0 ; i<20 ; ++i)for(int j=0 ; j<n ; ++j)ac[i][j]=0;
}
inline void solve(){
	IOS;
	while(cin >> n >> m){
		init();
		for(int i=1 ; i<n ; ++i){
			int a , b; cin >> a >> b;
			E[a].pb(b);
			E[b].pb(a);
		}
		dfs(0);
		build_lca();
		while(m--){
			int a , b , val;
			cin >> a >> b >> val;
			int m = lca(a,b);
			sum[a]+=val , sum[b]+=val , sum[m]-=val;
			if(ac[0][m] != m) sum[ac[0][m]]-=val;
		}
		vis.reset();
		dfs2(0);
		for(int i=0 ; i<n ; ++i) cout << sum[i] << ' ';	
		endl
	}
}
signed main(){solve();}