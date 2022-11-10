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
signed main(){
	IOS;
	string a,b;
	while(cin >> a >> b){
		int n = a.size() , m = b.size();
		vector< vector<int> > dp(n+1 , vector<int>(m+1,0));
		for(int i=1 ; i<=n ; ++i){
			for(int j=1 ; j<=m ; ++j){
				if(a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else{
					dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
				}
			}
		}
		cout << dp[n][m] << '\n';
	}
}