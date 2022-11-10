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
const int maxn = 10005;
const int inf = 1e9;
struct T
{
	int to , w , c;
	bool operator<(const T &a)const{
		if(to != a.to) return to < a.to;
		else if(w != a.w) return w < a.w;
		return c < a.c;
	}
};
int back[maxn] , dis[maxn] , cost[maxn] , n , m;
vector<T> v[maxn];
inline void dijkstra(){
	fill(back,back+n+1,-1);
	fill(dis,dis+n+1,inf);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	dis[1]=0,cost[1]=0,pq.push({1,0});
	while(pq.size()){
		int now = pq.top().F , w = pq.top().S;
		pq.pop();
		if(w != dis[now]) continue;
		for(auto &p : v[now]){
			if((dis[p.to] > p.w + dis[now]) or (dis[p.to]==dis[now]+p.w and cost[p.to]>p.c)){
				back[p.to] = now;
				dis[p.to] = dis[now]+p.w;
				cost[p.to] = p.c;
				pq.push({p.to , dis[p.to]});
			}
		}
	}
}
set<pii> s;
bitset<maxn> vis;
map<pii,int> MP;
int ans;
void dfs(int now){
	vis[now]=1;
	int a = min(now , back[now]);
	int b = max(now , back[now]);
	ans += MP[{a,b}];
	for(auto &p : v[now])
		if(!vis[p.to]){
			dfs(p.to);
		}
}

inline void latina(){
	loli;
	while(cin >> n >> m and n+m){
		//init
		for(int i=1 ; i<=n ; ++i) v[i].clear(),dis[i]=0,cost[i]=0,back[i]=-1;
		MP.clear(),vis.reset(),s.clear(),ans=0;
		//
		for(int i=0,a,b,w,c ; i<m ; ++i){
			cin >> a >> b >> w >> c;
			v[a].pb({b,w,c});
			v[b].pb({a,w,c});
			MP[{min(a,b),max(a,b)}]=c;
		}
		dijkstra();
		dfs(1);
		cout << ans << '\n';
	}
}
signed main(){latina();}