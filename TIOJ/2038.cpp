#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
// #define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;

const int maxn = 5005;
int fa[maxn], sz[maxn];

int Find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
}

void Union(int a, int b) {
	a = Find(a) , b = Find(b);
	if (a == b) return ;
	if (sz[a] < sz[b]) swap(a,b);
	fa[b] = a;
	sz[a] += sz[b];
}

vector<int> G[maxn];
set<int> fri[maxn];
set<pii> pq;
int in[maxn];
bool dead[maxn];

signed main(){
	fast;
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;

	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		in[a]++, in[b]++;
		fri[a].insert(b);
		fri[b].insert(a);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) pq.emplace(fri[i].size(), i);

	vector<pii> out;

	while(pq.size()) {
		auto [sz, who] = *pq.begin();
		pq.erase(pq.begin());
		dead[who] = true;
		out.emplace_back(who, sz);

		for (auto &adj : fri[who]) {
			if (dead[adj]) continue;
			//update pq
			pq.erase({fri[adj].size(), adj});
			fri[adj].erase(who);
			pq.emplace(fri[adj].size(), adj);
		}
	}

	reverse(ALL(out));

	int ans = 0;
	for (auto &[x,mn] : out) {
		dead[x] = false;
		for (int &y : G[x]) {
			//if y already insert into the graph
			if (!dead[y]) {
				Union(x, y);
			}
		}
		ans = max(ans, mn * sz[Find(x)]);
	}
	cout << ans << '\n';
}