#include<bits/stdc++.h>
#define test_
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define et cout<<'\n';
#define int long long
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
int cnt = 0;
int dp[1000][1000];
int dfs(int now , int last){
	if(now == 0) dp[now][last] = 1;
	if(dp[now][last] != -1) return dp[now][last];
	dp[now][last] = 0;
	for(int i=last ; i<=now ; i+=2){
		dp[now][last] += dfs(now-i , i);
	}
	return dp[now][last];
}
 main(){
__IO
	int T , n; cin >> T;
	while(T--){
		for(int i=0 ; i<=751 ; ++i){
			for(int j=0 ; j<751 ; ++j){
				dp[i][j] = -1;
			}
		}
		dp[1][1] = 1;
		cin >> n;
		cout << dfs(n , 1) << '\n';
	}
}