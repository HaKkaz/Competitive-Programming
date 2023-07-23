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

signed main(){
	fast;
	int n, m;
	cin >> n >> m;
	vector< vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	vector< pii > ans;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x = a[i][j];
			int sum = 0;
			for (int ii = 0; ii < n; ++ii) {
				for (int jj = 0; jj < m; ++jj) {
					if (abs(i - ii) + abs(j - jj) <= x) {
						sum += a[ii][jj];
					}
				}
			}
			if (sum % 10 == x) {
				ans.emplace_back(i,j);
			}
		}
	}

	cout << ans.size() << '\n';
	for (auto [x,y] : ans) 
		cout << x << ' ' << y << '\n';
}
