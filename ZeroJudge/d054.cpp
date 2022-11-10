#include<iostream>
#define int long long
using namespace std;
int dp[44];
main(){
	dp[1] = 1 , dp[2] = 5 , dp[3] = 11;
	for(int i=4 ; i<=40 ; ++i){
		dp[i] = dp[i-1] + 4*dp[i-2] + 2*dp[i-3];
	}
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		cout << dp[n] <<'\n';
	}
}