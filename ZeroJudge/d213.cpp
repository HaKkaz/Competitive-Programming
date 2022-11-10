#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int unsigned long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
signed main(){
	IOS;
	int n;
	pii dp[100];
	dp[0].F = 2;
	dp[0].S = 2;
	for(int i=1 ; i<=80 ; ++i){
		dp[i].F = dp[i-1].F + dp[i-1].S*2 - (i>=10 ? dp[i-10].S : 0);
		dp[i].S = dp[i-1].S*2;
	}
	while(cin >> n){
		cout << dp[n].F << '\n';
	}
}