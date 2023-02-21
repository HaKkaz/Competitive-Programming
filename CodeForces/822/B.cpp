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
		int n; cin >> n;
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<=i ; ++j){
				if(j==0 || j==i) cout << 1 << ' ';
				else cout << 0 << ' ' ;
			}
			cout << '\n';
		}
	}
}