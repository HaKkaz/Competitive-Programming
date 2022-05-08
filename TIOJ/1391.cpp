#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
// #define int long long
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
signed main(){
	IOS;
	const int inf = 1e9;
	int n ; 
	while(cin >> n){
		int dp[n+1][n+1];
		for(int i=0 ; i<=n ; ++i)for(int j=0 ; j<=n ; ++j)dp[i][j]=inf;
		int ans = 0 ;
		for(int i=1 ; i<=n ; ++i){
			for(int j=1 ; j<=i ; ++j){
				cin >> dp[i][j];
				if(i >= 2){
					dp[i][j] = max({dp[i][j] , min(dp[i-1][j] , dp[i-1][j-1])}) + 1;
				}
				ans = max(ans , dp[i][j]);
			}
		}
		cout << ans << '\n';
	}
}