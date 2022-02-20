#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
using namespace std;
#ifndef DEBUG
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(1);else cerr
#endif
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

const int MAXN = 2005;
const ll INF = 3e18;

struct MCMF { // 0-base
  struct edge {
    ll from, to, cap, flow, cost, rev;
  } * past[MAXN];
  vector<edge> G[MAXN];
  bitset<MAXN> inq;
  ll dis[MAXN], up[MAXN], s, t, mx, n;
  bool BellmanFord(ll &flow, ll &cost) {
    fill(dis, dis + n, INF);
    queue<ll> q;
    q.push(s), inq.reset(), inq[s] = 1;
    up[s] = mx - flow, past[s] = 0, dis[s] = 0;
    while (!q.empty()) {
      ll u = q.front();
      q.pop(), inq[u] = 0;
      if (!up[u]) continue;
      for (auto &e : G[u])
        if (e.flow != e.cap &&
          dis[e.to] > dis[u] + e.cost) {
          dis[e.to] = dis[u] + e.cost, past[e.to] = &e;
          up[e.to] = min(up[u], e.cap - e.flow);
          if (!inq[e.to]) inq[e.to] = 1, q.push(e.to);
        }
    }
    if (dis[t] == INF) return 0;
    flow += up[t], cost += up[t] * dis[t];
    for (ll i = t; past[i]; i = past[i]->from) {
      auto &e = *past[i];
      e.flow += up[t], G[e.to][e.rev].flow -= up[t];
    }
    return 1;
  }
  ll MinCostMaxFlow(ll _s, ll _t, ll &cost) {
    s = _s, t = _t, cost = 0;
    ll flow = 0;
    while (BellmanFord(flow, cost))
      ;
    return flow;
  }
  void init(ll _n, ll _mx) {
    n = _n, mx = _mx;
    for (int i = 0; i < n; ++i) G[i].clear();
  }
  void add_edge(ll a, ll b, ll cap, ll cost) {
    G[a].push_back(edge{a, b, cap, 0, cost, G[b].size()});
    G[b].push_back(edge{b, a, 0, 0, -cost, G[a].size() - 1});
  }
}solve;

int root[2] , limit[2][505] , sum[2][505] , a[505];
vector<int> G[2][505];

void dfs(int x , int f , int i){
    for(int &y : G[i])
        if(f != y){
            dfs(y , x , i);
            sum[i][x] += sum[i][y] + limit[i][y];
        }
}

int main(){
    int n,x,y;
    cin >> n >> root[0] >> root[1];
    for(int i=1 ; i<=n ; ++i) cin >> a[i];

    for(int i=0 ; i<2 ; ++i){
        for(int j=0 ; j<n ; ++j){
            int a,b; cin >> a >> b;
            G[i][a].push_back(b);
            G[i][b].push_back(a);
        }
    }

    for(int i=0 ; i<2 ; ++i){
        int q; cin >> q;
        while(q--){
            int k,x; cin >> k >> x;
            limit[i][k] = x;
        }
        dfs(root[i] , root[i] , i);
    }
    
    
}
