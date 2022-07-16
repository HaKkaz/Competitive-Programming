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
	int n ;
	cin >> n ; 
	vector<int> a(n);
	for(int i=0 ; i<n ; ++i) cin >> a[i];

	const int inf = 2e18;
	vector<int> dp(n , inf) , dp2(n , inf);

	dp[0] = dp[1] = a[0];
	for(int i=1 ; i<n-1 ; ++i){
		dp[i+1] = min(dp[i-1] + a[i] , dp[i] + min(a[i],a[i+1]));
	}

	int tmp = a[n-1];
	for(int i=n-1 ; i>=1 ; --i){
		a[i] = a[i-1];
	}
	a[0] = tmp;


	dp2[0] = dp2[1] = a[0];
	for(int i=1 ; i<n-1 ; ++i){
		dp2[i+1] = min(dp2[i-1] + a[i] , dp2[i] + min(a[i],a[i+1]));
	}

	// for(int i=0 ; i<n ; ++i) cout << a[i] << " \n"[i==n-1];
	// for(int i=0 ; i<n ; ++i) cout << dp2[i] << " \n"[i==n-1];


	cout << min(dp[n-1] , dp2[n-1]) << '\n';
}