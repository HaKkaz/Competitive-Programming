#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
bool LCS(string &a , string &b){
	int n = a.size();
	int m = b.size();
	vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));
	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j){
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}
	return 1.0*dp[n][m] >= 1.0*(min(n,m))/2.0;
}
int Find(int x , vector<int> &fa){
	if(x == fa[x]) return x;
	else return fa[x] = Find(fa[x] , fa);
}
void Union(int a , int b , vector<int> &fa , vector<int> &sz){
	a = Find(a , fa) , b = Find(b , fa);
	if(a == b) return;
	fa[b] = a;
	sz[a] += sz[b];
}
signed main(){
	IOS;
	int t=1;
	cin >> t;
	while(t--){
		int n;
		cin >> n ;
		vector<string> strs(n);
		vector<int> fa(n) , sz(n,1);
		iota(fa.begin() , fa.end() , 0);
		for(auto &s : strs) cin >> s;
		for(int i=0 ; i<n ; ++i){
			for(int j=i+1 ; j<n ; ++j){
				if(LCS(strs[i] , strs[j])) Union(i , j , fa , sz);
			}
		}
		cout << *max_element(all(sz)) << '\n';
	}
}
