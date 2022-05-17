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

//dp[i][j] indicate the i-th customer end in j-th product

signed main(){
	fast;
	int t; cin >> t;
	for(int T=1 ; T<=t ; ++T){
		cout << "Case #" << T << ": ";
		int n , m ; cin >> n >> m ;
		vector< vector<int> > dp(n+1 , vector<int>(m,0));
		vector< vector<int> > Ps(n+1 , vector<int>(m,0));
		for(int i=1 ; i<=n ; ++i)for(int j=0 ; j<m ; ++j)cin >> Ps[i][j];
		for(int i=1 ; i<=n ; ++i)
		{
			sort(ALL(Ps[i]));
			for(int j=0 ; j<m ; ++j){
				dp[i][j] = 1e18;
				for(int k=0 ; k<m ; ++k){
					if(Ps[i-1][k] <= Ps[i][0]){
						dp[i][j] = min(dp[i][j] , dp[i-1][k] + Ps[i][m-1] - Ps[i-1][k] + Ps[i][m-1] - Ps[i][j]);
					}
					else if(Ps[i-1][k] >= Ps[i][m-1]){
						dp[i][j] = min(dp[i][j] , dp[i-1][k] + Ps[i-1][k] - Ps[i][0] + Ps[i][j] - Ps[i][0]);	
					}
					else{

						dp[i][j] = min({dp[i][j] , 
							dp[i-1][k] + (Ps[i-1][k] - Ps[i][0]) + (Ps[i][m-1] - Ps[i][0]) + (Ps[i][m-1] - Ps[i][j]),
							dp[i-1][k] + (Ps[i][m-1] - Ps[i-1][k]) + (Ps[i][m-1] - Ps[i][0]) + (Ps[i][j] - Ps[i][0])
						});
					}
				}
			}

		}
		cout << *min_element(dp[n].begin() , dp[n].end()) << endl;
	}
}