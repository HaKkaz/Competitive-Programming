#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 2005;
vector<pii> v[maxn];
bitset<maxn> vis;
int cnta[maxn],ans;
void dfs(int now , int d , int id){
	if(cnta[now]==0){
		ans = max(d , ans);
	}
	for(auto &c : v[now]){
		if(!vis[c.F] and c.S == id){
			vis[c.F]=1;
			dfs(c.F , d+1 , 1-id);
			vis[c.F]=0;
		}
	}
}
inline void latina(){
	loli;
	int m , n , k , l;
	while(cin >> m >> n >> k >> l){
		//init
		ans=0;
		for(int i=1 ; i<=m ; ++i) v[i].clear(),cnta[i]=0;
		for(int i=1001 ; i<=n+1000 ; ++i) v[i].clear(),cnta[i]=0;
		//
		for(int i=0,a,b,w ; i<k ; ++i){
			cin >> a >> b >> w , b+=1000;
			v[a].pb({b,w});
			v[b].pb({a,w});
			if(w)cnta[a]++,cnta[b]++;
		}
		for(int i=1 ; i<=m ; ++i){
			if(cnta[i]==0)
				dfs(i , 0 , 0);
		}
		for(int i=1001 ; i<=n+1000 ; ++i){
			if(cnta[i]==0){
				dfs(i , 0 , 0);
			}
		}
		if(ans)cout << ans << '\n';
		else cout << -1 << '\n';
	}
}
signed main(){latina();}