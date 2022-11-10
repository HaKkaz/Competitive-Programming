#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 205;
int dp[maxn][maxn] , a[maxn];
inline void latina(){
	loli;
	int t; cin >> t;
	while(t--){
		int n , m;  cin >> n >> m;
		for(int i=0 ; i<n ; ++i) for(int j=0 ; j<n ; ++j) dp[i][j] = 1e9;
		for(int i=0 ; i<n ;++i) dp[i][i]=1;
		for(int i=0 ; i<n ; ++i) cin >> a[i];
		for(int x=2 ; x<=n ; ++x){
			for(int l=0 ; l+x-1<n ; ++l){
				int r = l+x-1;
				for(int m=l ; m<r ; ++m){
					dp[l][r] = min(dp[l][r] , dp[l][m]+dp[m+1][r]);
				}
				if(a[l]==a[r]) dp[l][r]--;
			}
		}
		cout << dp[0][n-1] << '\n';
	}
}
signed main(){latina();}