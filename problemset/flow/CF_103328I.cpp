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

const int MAXN = 5050;
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

int main(){

    int n , m , k;
    cin >> n >> m >> k;
    //S : 0 , T : 3502 , edges : 1 ~ 3000 , nodes : 3001 ~ 3500 , delete : 3501
    solve.init(3600 , INF);
    for(int i=1 ; i<=m ; ++i){
        int a,b,w1,w2;
        cin >> a >> b >> w1 >> w2;
        solve.add_edge(0,i,1,0);
        solve.add_edge(i,b+3000,1,0);
        solve.add_edge(i,a+3000,1,w1);
        solve.add_edge(i,3501,1,w2);
    }
    solve.add_edge(3501,3502,INF,0);
    for(int i=1 ; i<=n ; ++i) solve.add_edge(i+3000 , 3502 , k , 0);
    ll cost = 0;
    solve.MinCostMaxFlow(0 , 3502 , cost);
    cout << cost << '\n';
}
