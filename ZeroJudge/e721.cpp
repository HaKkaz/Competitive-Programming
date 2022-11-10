#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int a[10005] , dp[505] , ans=0;
signed main(){
	IOS;
	int n; cin >> n ;
	for(int i=0 ; i<n ; ++i){
		int x; cin >> x;
		a[x]++;
	}
	dp[1] = a[1];
	for(int i=2 ; i<=500 ; ++i){
		dp[i] = max(dp[i-1] , dp[i-2]+a[i]*i);
		ans = max(ans , dp[i]);
		// cout << dp[i] <<' ';
	}
	cout << ans << '\n';
}