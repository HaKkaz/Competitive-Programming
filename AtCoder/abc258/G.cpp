#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
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

bitset<3000> has[3000];

signed main(){
	fast;
	int n; cin >> n ;
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<n ; ++j){
			char x; cin >> x ;
			if(x == '1') has[i][j] = 1;

		}
		has[i][i] = 0;
	}
	long long ans = 0;
	for(int i=0 ; i<n ; ++i){
		for(int j=i+1 ; j<n ; ++j){
			auto cnt = (has[i] & has[j]).count();
			if(has[i][j]) {
				ans += cnt;
			}
		}
	}
	cout << (ans/3) << '\n';
}