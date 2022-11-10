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
const int maxn = 40000;
vector<int> v[maxn];
//HLD
int fa[maxn] , child[maxn] , deep[maxn] , newid[maxn] , son[maxn] , top[maxn] , cnt=1 , n;
int dfs1(int now , int last , int dep){
	fa[now] = last;
	child[now] = 1;
	deep[now] = dep;
	int maxson = -1;
	for(auto &c : v[now]){
		if(c != last){
			int tot = dfs1(c , now , dep+1);
			if(maxson < tot) maxson = tot , son[now] = c;
			child[now] += tot;
		}
	}
	return child[now];
}
void dfs2(int now , int topf){
	newid[now] = cnt++;
	top[now] = topf;
	if(son[now]==-1) return;
	dfs2(son[now] , topf);
	for(auto &c : v[now]){
		if(!newid[c]){
			dfs2(c , c);
		}
	}
}
//segment Tree
int sum[maxn<<2];
int query(int l , int r , int ql , int qr , int rt){
	if(ql <= l and r <= qr) return sum[rt];
	int m = (l+r)>>1;
	if(qr <= m) return query(l , m , ql , qr , rt<<1);
	if(ql >  m) return query(m+1 , r , ql , qr , rt<<1|1);
	return query(l , m , ql , qr , rt<<1) + query(m+1 , r , ql , qr , rt<<1|1);
}
void modify(int l , int r , int id , int rt , int k){
	if(l==r and l==id) return sum[rt] += k, void();
	int m = (l+r)>>1;
	if(id <= m) modify(l , m , id , rt<<1 , k);
	if(id >  m) modify(m+1 , r , id , rt<<1|1 , k);
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
//
void solve(){
	int a , k;
	cin >> a >> k ;
	modify(1 , n , newid[a] , 1 , k);
	int ans = 0;
	while(top[a] != top[0]){
		ans += query(1 , n , newid[top[a]] , newid[a] , 1);
		a = fa[top[a]];
	}
	ans += query(1 , n , newid[0] , newid[a] , 1);
	cout << ans << '\n';
}
inline void latina(){
	loli;
	while(cin >> n){
		for(int i=0 ; i<n ; ++i) son[i]=-1 , newid[i]=0 , cnt=1 , v[i].clear();
		fill(sum,sum+(n<<2),0);
		for(int i=1,a,b ; i<n ; ++i) cin >> a >> b , v[a].pb(b) , v[b].pb(a);
		dfs1(0 , -1 , 1);
		dfs2(0 , 0);
		int m; cin >> m;
		while(m--) solve();
		cout << '\n';
	}
}
signed main(){latina();}