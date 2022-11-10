#include<bits/stdc++.h>
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define rz(n) resize(n)
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
using namespace std;
const int inf = numeric_limits<int>::max();
const int maxn = 5005;
const int maxm = 5005*5005;
int ans , n , m;
int f[maxn] , ch[maxn] , cnt[maxn] , used[maxn] , add[maxn] , adj[maxn][maxn];
vector<pii> stk;
vector<int> E[maxn] , num;
int F(int x){
	if(x == f[x]) return x;
	return f[x] = F(f[x]);
}
void Union(int a , int b){
	a = F(a) , b = F(b);
	if(a == b) return;
	f[b] = a;
	ch[a] += ch[b];
}
inline void solve(){
	cin >> n >> m;
	for(int i=1 ; i<=n ; ++i) f[i] = i , ch[i] = 1;
	for(int i=1 ; i<=m ; ++i){
		int a , b ;
		cin >> a >> b;
		E[a].pb(b) , E[b].pb(a);
		cnt[a]++ , cnt[b]++;
	}
	while(1){
		int mn = 1e9;
		deque<int> v;
		for(int i=1 ; i<=n ; ++i) 
			if(!used[i]) mn = min(mn , cnt[i]);
		if(mn == 1e9) break;
		for(int i=1 ; i<=n ; ++i){
			if(!used[i] and cnt[i] == mn){
				used[i] = 1 , v.pb(i);
			}
		}
		while(v.size()){
			int now = v.back(); v.pop_back();
			stk.pb({now , mn});
			for(auto &c : E[now]){
				if(!used[c] and --cnt[c] <= mn){
					v.pb(c) , used[c] = 1;
				}
			}
		}
	}
	for(int i=n+100 ; i>=0 ; --i){
		while(stk.size() and stk.back().S == i){
			int a = stk.back().F ;stk.pop_back();
			add[a] = 1;
			for(auto &c : E[a]){
				int b = c;
				if(add[b]){
					Union(a , b);
				}
			}
			ans = max(ans , ch[F(a)]*i);
		}
	}
	cout << ans << '\n';
}
signed main(){IOS;solve();}