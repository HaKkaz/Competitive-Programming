#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
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
	int n=1;
	while(cin >> n){
		if(n == 2){
			string s[2]; cin >> s[0] >> s[1];
			const int N = s[0].size();
			const int M = s[1].size();
			vector< vector<int> > dp(N+1 , vector<int>(M+1,0));
			for(int i=1 ; i<=N ; ++i){
				for(int j=1 ; j<=M ; ++j){
					if(s[0][i-1] == s[1][j-1]) dp[i][j] = dp[i-1][j-1] + 1;
					else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
				}
			}
			cout << dp[N][M] << '\n';
		}
		if(n == 3){
			string s[3]; cin >> s[0] >> s[1] >> s[2];
			const int N = s[0].size();
			const int M = s[1].size();
			const int K = s[2].size();
			vector< vector< vector<int> > > dp(N+1 , vector< vector<int> >(M+1,vector<int>(K+1,0)));
			for(int i=1 ; i<=N ; ++i){
				for(int j=1 ; j<=M ; ++j){
					for(int k=1 ; k<=K ; ++k){
						if(s[0][i-1] == s[1][j-1] and s[1][j-1] == s[2][k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
						else dp[i][j][k] = max({dp[i-1][j][k] , dp[i][j-1][k] , dp[i][j][k-1]});
					}
				}
			}
			cout << dp[N][M][K] << '\n';
		}
	}
}