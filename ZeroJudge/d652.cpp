#include<iostream>
#include<math.h>
using namespace std;
#define int long long
const int inf = 2147483647;
int dp[51][51] , num[51] , n;
void init(){
for(int i=0 ; i<=n ; ++i)
	for(int j=0 ; j<=n ; ++j)
		dp[i][j] = inf;
}
signed main(){
	cin >> n;
	for(int i=1 ; i<=n ; ++i){
		cin >> num[i];
	}
	for(int i=1 ; i<n ; ++i){
		for(int l=1 , r=l+i ; r<n ; ++l , ++r){
			int mn = inf;
			for(int m = l ; m < r ; ++m){
				mn = min(mn , dp[l][m] + dp[m+1][r] + num[l]*num[m+1]*num[r+1]);
			}
			dp[l][r] = mn;
		}
	}
	cout << dp[1][n-1] << '\n';
}