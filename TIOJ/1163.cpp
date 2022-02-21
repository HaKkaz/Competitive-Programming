#include<bits/stdc++.h>
#define pb push_back
#define S second
#define F first
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
using namespace std;
const int maxn = 30005;
int n , m , ac[40][maxn] , mx[40][maxn] , in[maxn] , out[maxn] , cnt , vis[maxn];
vector<pii> E[maxn];
struct edge
{
	int a , b , w;
	bool operator<(const edge &x)const{
		return w < x.w;
	}
};
deque<edge> dq;
vector<edge> edges;
int f[maxn] , _sz[maxn];
int F(int x){return x==f[x]?x:f[x]=F(f[x]);}
bool U(int a , int b){
	a = F(a) , b = F(b);
	if(a == b) return 0;
	if(_sz[a] < _sz[b]) swap(a , b);
	f[b] = a;
	_sz[a] += _sz[b];
	return 1;
}
void kruskal(){
	for(int i=1 ; i<=n ; ++i) f[i] = i , _sz[i] = 1;
	sort(all(dq));
	while(dq.size()){
		int a = dq.front().a , b = dq.front().b , w = dq.front().w;
		dq.pop_front();
		if(U(a , b)){
			E[a].pb({b , w});
			E[b].pb({a , w});
		}
	}
}
void dfs(int now , int lst){
	vis[now] = 1;
	in[now] = ++cnt;
	for(auto &c : E[now]){
		if(c.F != lst){
			ac[0][c.F] = now;
			mx[0][c.F] = c.S;
			dfs(c.F , now);
		}
	}
	out[now] = ++cnt;
}
inline bool anc(int a , int b){
	if(in[a] <= in[b] and out[a]>=out[b]) return 1;
	return 0;
}
inline void build_lca(){
	for(int i=1 ; i<=n ; ++i){
		if(!vis[i]){
			ac[0][i] = i;
			dfs(i , -1);
		}
	}
	for(int i=1 ; i<=30 ; ++i){
		for(int j=1 ; j<=n ; ++j){
			ac[i][j] = ac[i-1][ac[i-1][j]];
			mx[i][j] = max(mx[i-1][ac[i-1][j]] , mx[i-1][j]);
		}
	}
}
inline void qry(int a , int b){
	if(a == b) return cout << 0 << '\n' , void();
	if(F(a) != F(b)) return cout << -1 << '\n' , void();
	int ans = 0;
	for(int i=30 ; i>=0 ; --i){
		if(!anc(ac[i][a] , b)) ans = max(ans , mx[i][a]) , a = ac[i][a];
	}
	swap(a , b);
	for(int i=30 ; i>=0 ; --i){
		if(!anc(ac[i][a] , b)) ans = max(ans , mx[i][a]) , a = ac[i][a];
	}
	if(anc(a , b) and a != b) ans = max(ans , mx[0][b]);
	else if(anc(b , a) and a != b) ans = max(ans , mx[0][a]);
	else{
		ans = max(ans , mx[0][a]);
		ans = max(ans , mx[0][b]);
	}
	cout << ans << '\n';
}
inline void solve(){
	cin >> n >> m ;
	for(int i=0 ; i<m ; ++i){
		int a , b , w;
		cin >> a >> b >> w;
		dq.pb({a , b , w});
	}
	kruskal();
	build_lca();
	int q; cin >> q;
	for(int i=0 ; i<q ; ++i){
		int a , b ;
		cin >> a >> b;
		qry(a , b);
	}	
}
signed main(){IOS;solve();}