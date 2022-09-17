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
	int W,E,N;
	cin >> W >> E >> N;
	vector<pii> skills(N);
	for(auto &[D,A]:skills) cin >> D >> A;
	vector<int> dp0(10005,0);
	dp0[0] = 0;
	for(int i=0 ; i<N ; ++i){
		auto &[D,A] = skills[i];
		vector<int> dp1(dp0);
		for(int j=0 ; j<=W ; ++j){
			if(j + D <= W) 
				dp1[j + D] = max(dp1[j + D] , dp0[j] + A);
		}
		dp0 = dp1;
	}
	for(int i=0 ; i<W ; ++i){
		if(dp0[i] >= E){
			cout << W - i << '\n';
			return 0;
		}
	}
	cout << "wryyyyyyyyyyyyy\n";
}