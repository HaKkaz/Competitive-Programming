#include<bits/stdc++.h>
#define int long long
//#define test_
#define MP make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define et cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
const int maxn = 45;
int a , b , res;
vector<int> v;
int dp[maxn][2];
signed main(){__IO
	v.resize(45);
	int n; 
	while(cin >> n && n){	
		for(int i=0 ; i<n ; ++i) dp[i][0] = dp[i][1] = 0 , cin >> v[i];
		dp[0][0] = v[0] , dp[0][1] = v[0]*2;
		for(int i=1 ; i<n ; ++i){
			dp[i][0] = max(dp[i-1][1] , dp[i-1][0]+v[i]);
			dp[i][1] = dp[i-1][0]+v[i]*2;
		}
		cout << max(dp[n-1][0] , dp[n-1][1]) << '\n';
	}
}