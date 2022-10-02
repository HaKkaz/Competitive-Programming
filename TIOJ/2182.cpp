#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
int dp[1005][1005] , a[1005][1005];
signed main(){
	IOS;
	int n , m; cin >> n >> m ;
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; ++j)
			cin >> a[i][j];
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j){
			dp[i][j] = max({dp[i-1][j] + a[i][j] , dp[i][j-1] + a[i][j] , a[i][j]});
		}
	}
	int ans = -1e9;
	for(int i=1 ; i<=m ; ++i) ans = max(ans , dp[n][i]);
	for(int i=1 ; i<=n ; ++i) ans = max(ans , dp[i][m]);
	cout << ans << '\n';
}