#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define ft first
#define sd second
#define ALL(v) v.begin(),v.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 
const int mod = 998244353;
ll dp[5005][5005];
int main(){
	fast;
	int n , m ; cin >> n >> m ;
	dp[0][0] = 1;
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=n ; ++j){
			if(j - (i-1)/m <= 0) dp[i][j] = 0;
			else{
				dp[i][j] = (dp[i-1][j-1] + (dp[i-1][j] * (j - (i-1)/m)%mod) )%mod;
			}
		}
	}
	for(int i=1 ; i<=n ; ++i) cout << dp[n][i] << '\n';
}

