#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define int long long
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

const int inf = 1e18;
vector<int> v[100050];
int ddis[20][20];

int BFS(int st, int ed) {
	vector<int> dis(100050, -1);
	queue<int> q;
	q.push(st);
	dis[st] = 0;

	while (q.size()) {
		int now = q.front();
		q.pop();
		for (int &nxt : v[now]) {
			if (dis[nxt] == -1) {
				q.push(nxt);
				dis[nxt] = dis[now] + 1;
			}
		}
	}

	return dis[ed];
}

int dp[(1<<20)][20];

signed main(){
	fast;
	int n, m;
	cin >> n >> m ;
	while (m--) {
		int a,b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int k; cin >> k;
	vector<int> c(k);
	for (int i = 0; i < k; ++i) cin >> c[i];
	
	//shortest-path table
	for (int i = 0; i < k; ++i) {
		for (int j = i + 1; j < k; ++j) {
			if (i != j) ddis[i][j] = BFS(c[i],c[j]);
		}
	}

	for (int i = 0 ; i < (1 << k); ++i) {
		for (int j = 0; j < k; ++j) {
			dp[i][j] = inf;
		}
	}

	for (int i = 0; i < k; ++i) {
		dp[(1 << i)][i] = 1;
	}

	for (int i = 0; i < (1 << k); ++i) {
		for (int ed = 0; ed < k; ++ed) {
			if (i >> ed & 1) { 
				for (int st = 0; st < k; ++st) {
					if ((i ^ (1<<ed)) & (1 << st)) {
						int dd = st > ed ? ddis[ed][st] : ddis[st][ed];
						if(dd != -1) {
							dp[i][ed] = min(dp[i][ed], dp[(i ^ (1 << ed))][st] + dd);
						}
					}
				}
			}
		}
	}
	int ans = *min_element(dp[(1 << k)-1] , dp[(1 << k)-1] + k);
	cout << (ans == inf ? -1 : ans) << '\n';
}