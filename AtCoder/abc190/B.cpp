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
	int n, s, d;
	cin >> n >> s >> d;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a < s && b > d) return cout << "Yes\n" , 0;
	}
	cout << "No\n";
}