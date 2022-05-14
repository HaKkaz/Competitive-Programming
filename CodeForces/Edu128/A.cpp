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

signed main(){
	fast;
	int t=1;
	cin >> t;
	while(t--){
		int l,r,L,R;
		cin >> l >> r >> L >> R;
		int mn = max(l,L);
		if(mn > r || mn > R){
			cout << l + L << '\n';
		}
		else{
			cout << mn << '\n';
		}
	}
}