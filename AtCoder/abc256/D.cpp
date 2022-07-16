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
	int n; cin >> n ;
	vector< pair<int,int> > ans , vv;
	for(int i=0 ; i<n ; ++i){
		int l,r; cin >> l >> r;
		vv.emplace_back(l,r);
	}

	sort(ALL(vv));

	int L = 0 , R = -1;
	for(auto &[l,r] : vv){
		if(l > R){
			if(R-L+1 != 0){
				ans.emplace_back(L,R);
			}
			L = l , R = r;
		}
		else{
			R = max(R , r);
		}
	}
	ans.emplace_back(L,R);
	for(auto [l,r] : ans) cout << l << ' ' << r << '\n';
}