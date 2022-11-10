#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define PB push_back
#define MP make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int dp[51][51];
int n , m ;
int le(int x){
	--x;
	if(x<1) return n;
	return x;
}
int ri(int x){
	++x;
	if(x>n) return 1;
	return x;
}
int main(){
__IO
	cin >> n >> m;
	dp[1][n] = dp[1][2] = 1;
	//i 次數 j位置
	for(int i=2 ; i<=m ; ++i)
		for(int j=1 ; j<=n ; ++j)
			dp[i][j] = dp[i-1][le(j)] + dp[i-1][ri(j)];
	cout << dp[m][1] << '\n';
}