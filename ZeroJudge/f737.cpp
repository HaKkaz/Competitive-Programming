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
	int n,U; cin >> n >> U;
	vector< vector<int> > farm(n+1 , vector<int>(n+1,0));
	vector< vector<int> > psum(n+1 , vector<int>(n+1,0));
	vector< vector<int> > dp(n+1 , vector<int>(n+1,0));
	int ans = 0;
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=n ; ++j){
			cin >> farm[i][j];
			psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + farm[i][j];
			if(farm[i][j] == -1) dp[i][j] = 0;
			else{
				int mn = min(dp[i-1][j] , dp[i][j-1]);
				dp[i][j] = mn + (farm[i-mn][j-mn] != -1);
			}
			int h = dp[i][j];
			int cost = psum[i][j] - psum[i-h][j] - psum[i][j-h] + psum[i-h][j-h];
			if(cost <= U && ans < h * h){
				ans = h * h;
			}
		}
	}
	cout << ans << '\n';
}