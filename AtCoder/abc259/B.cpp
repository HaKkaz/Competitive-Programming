#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
long double pi = 3.14159265359;
signed main(){
	fast;
	int t=1;
	// cin >> t;
	while(t--){
		long double x,y; cin >> x >> y;
		long double d ; cin >> d;
		d = d * pi / 180.;
		cout << fixed << setprecision(10) << cos(d) * x + -sin(d) * y << ' ' << sin(d) * x + cos(d) * y << '\n';
	}
}