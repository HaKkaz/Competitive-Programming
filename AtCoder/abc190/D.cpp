// N = (l + r) * (r - l + 1) / 2
// 2 * n = (l + r) * (r - l + 1)
// 2 * n = (-l^2 + l) + (r^2 + r)
// 2 * n = (r + l) * (r - l) + l + r
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
	int n; cin >> n ;
	int ans = 0 ;
	for (int len = 1; len * len <= n * 2; ++len) {
		int add = (len) * (len-1) / 2;
		ans += (n - add) % len == 0;
	}
	cout << ans * 2 << '\n';
}