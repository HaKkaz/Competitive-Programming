#include<bits/stdc++.h>
#define test_
#define pb push_back
#define S second
#define F first
#define Sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define et cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
#define int long long
const int maxn = 105;
int num[maxn][maxn] , sum[maxn][maxn] , n , m , dp[maxn][maxn] , mx[maxn][maxn];
void buildsum(){
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; ++j)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] + num[i][j] - sum[i-1][j-1];
}
void solve(){
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; ++j){
			dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			for(int a = 0 ; a<i ; ++a){
				for(int b = 0 ; b<j ; ++b){
					int i2 = i-a , j2 = j-b;
					dp[i][j] = max(dp[i][j] , dp[i2-1][j2-1] + sum[i][j] - sum[i2-1][j] - sum[i][j2-1] + sum[i2-1][j2-1]);
				}
			}
		}
	cout << dp[n][m];
	et;
}
signed main(){
__IO
	cin >> n >> m;
	if(n == 1){
		long long ans = LLONG_MIN;
		long long x , sum = 0;
		for(int i=0 ; i<m ; ++i){
			cin >> x;
			sum += x;
			ans = max(ans , sum);
			if(sum < 0) sum = 0;
		}
		cout << ans << '\n';
		return 0;
	}
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; ++j)
			cin >> num[i][j];
	buildsum();
	solve();/*
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j){
			cout << dp[i][j] << ' ';
		}
		et
	}*/
}