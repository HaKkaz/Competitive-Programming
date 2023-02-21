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

int a[100], b[100], ball[16][2];

signed main(){
	fast;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a[i] >> b[i];
	}

	int k; cin >> k ;
	for (int i = 0; i < k; ++i) {
		cin >> ball[i][0] >> ball[i][1];
	}

	int ans = 0;
	for (int i = 0; i < (1 << k); ++i) {
		array<int,100> cnt{};
		for (int j = 0; j < k; ++j) {
			cnt[ ball[j][(i >> j & 1)] ]++;
		}

		int con = 0;
		for (int j = 0; j < m; ++j) {
			if (cnt[a[j]] && cnt[b[j]]) {
				++con;
			}
		}
		ans = max(ans, con);

	}
	cout << ans << '\n';
}
