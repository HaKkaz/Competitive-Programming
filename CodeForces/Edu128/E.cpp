#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
// #define int long long
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

signed main(){
	fast;
	int t=1;
	cin >> t;
	while(t--){
		int n ; cin >> n ;;
		vector< vector<int> > dp(2,vector<int>(n+1,0));
		vector< string > v(2,"");
		cin >> v[0] >> v[1];
		while(v[0].size() && v[0].back() == '.' and v[1].back() == '.'){
			v[0].pop_back();
			v[1].pop_back();
		}
		reverse(ALL(v[0]));
		reverse(ALL(v[1]));
		while(v[0].size() && v[0].back() == '.' and v[1].back() == '.'){
			v[0].pop_back();
			v[1].pop_back();
		}

		n = (int)v[0].size();
		if(v[0][0] == '*' && v[1][0] == '*') dp[0][1] = dp[1][1] = 1;
		else if(v[0][0] == '*') dp[0][1] = 0 , dp[1][1] = 1;
		else if(v[1][0] == '*') dp[0][1] = 1 , dp[1][1] = 0;

		for(int i=2 ; i<=n ; ++i){
			if(v[1][i-1] != '*') dp[0][i] = min(dp[0][i-1] + 1 , dp[1][i-1] + 2);
			else  				 dp[0][i] = min(dp[0][i-1] + 2 , dp[1][i-1] + 2);

			if(v[0][i-1] != '*') dp[1][i] = min(dp[1][i-1] + 1 , dp[0][i-1] + 2);
			else  				 dp[1][i] = min(dp[1][i-1] + 2 , dp[0][i-1] + 2);
		}

		cout << min(dp[0][n] , dp[1][n]) << '\n';
	}
}
/*
1
6
...*..
..*...
*/