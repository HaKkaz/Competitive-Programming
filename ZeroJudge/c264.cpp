#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
int dp[205][1005][205];
vector<pii> v(1, {0,0});
int main(){
	int n, t, l , x ,y ,ans=0;
	cin >> n >> t >> l;
	for (int i = 0; i < n; v.push_back({x,y}), ++i) cin >> x >> y;
		sort(v.begin(),v.end(),greater<pii>());
	for (int i= 1; i <= n; ++i){
		for (int j = 0; j <= t; ++j){
			for (int k = 1; k <= l; ++k){
				if(j-v[i].F*k >=0 ) dp[i][j][k] = max(dp[i][j][k-1],max(dp[i - 1][j - v[i].F * k][k - 1]+v[i].S, dp[i - 1][j][k]));
				else dp[i][j][k] = dp[i - 1][j][k];
			}
		}
	}
	for(int i=1 ; i<= l ; ++i) ans = max(dp[n][t][i],ans);
	cout << ans << '\n';
}