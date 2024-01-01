#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define fast
#else
#define fast cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define cerr if(1); else cerr
#endif
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

bool vis[200];
vector<pii> v[20];
int ans = 0;

void dfs(int cur, int sum = 0) {
    vis[cur] = 1;
    ans = max(ans, sum);
    for (auto [nxt, w] : v[cur]) {
        if (!vis[nxt]) {
            dfs(nxt, sum + w);
        }
    }
    vis[cur] = 0;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].emplace_back(b, w);
        v[b].emplace_back(a, w);
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i);
    }
    cout << ans << '\n';
}

