#include<bits/stdc++.h>
#define test_
#define PB push_back
#define S second
#define F first
#define Size(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
const long long llMAX=2e18+20020522;
const unsigned long long ullMAX=1e19+20020522;
const int imax = 2e9+20020522;
using namespace std;
#define int unsigned long long 
pii dp[50];
main(){
__IO
	 int n; cin >> n;
	 dp[1].F = 1 , dp[1].S = 2;
	 for(int i=2 ; i<=n ; ++i){
	 	dp[i].F = dp[i-1].F + dp[i-1].S;
	 	dp[i].S = dp[i-1].F*2 + dp[i-1].S;
	 }
	 cout << dp[n].F + dp[n].S <<'\n';
}