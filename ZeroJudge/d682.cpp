#include<bits/stdc++.h>
//#include<cstdio>
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
/*
inline int read(){
	int res=0; char ch=getchar_unlocked();
	while(ch<'0'||ch>'9') ch=getchar_unlocked();
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar_unlocked();
	return res;
}
*/
#define mp make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
#define LINE cout << "-----------------------\n";
using namespace std;
const int maxm = 2e4+50;
const int inf = 2e9;
int dp[2][maxm];
signed main(){
	IOS;
	int m , n , p;
	cin >> m >> n >> p;
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<=m ; ++j) dp[i&1][j] = 0;
		for(int k=0 ; k<p ; ++k){
			int val , gt;
			cin >> val >> gt;
			for(int j=0 ; j<=m ; ++j){
				if(j-val >= 0) dp[i&1][j] = max({dp[i&1][j] , dp[!(i&1)][j-val]+gt , dp[!(i&1)][j]});
				else dp[i&1][j] = max(dp[i&1][j] , dp[!(i&1)][j]);
			}
		}
	}
	cout << dp[!(n&1)][m] << '\n';
}