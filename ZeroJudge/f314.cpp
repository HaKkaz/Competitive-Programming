#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int maxn = 1e4+500;
const int inf = 1e9;
int a[maxn] , dp[2][maxn];
signed main(){
	IOS;
	int m,n;
	cin >> m >> n ;
	while(m--){
		int L[maxn] , R[maxn];
		fill(L , L+n+1 , -inf);
		fill(R , R+n+1 , -inf);
		for(int i=1 ; i<=n ; ++i) cin >> a[i];
		for(int i=1 ; i<=n ; ++i){
			L[i] = max(L[i-1]+a[i] , dp[0][i] + a[i]);
		}
		for(int i=n ; i>=1 ; --i){
			R[i] = max(R[i+1]+a[i] , dp[0][i] + a[i]);
		}
		for(int i=1 ; i<=n ; ++i){
			dp[1][i] = max(L[i] , R[i]);
		}
		swap(dp[0] , dp[1]);
	}
	cout << *max_element(dp[0]+1 , dp[0]+n+1) << '\n';
}