#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define rz(n) resize(n)
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
#define LINE cout << "-----------------------\n";
using namespace std;
const int inf = numeric_limits<int>::max();
const int maxn = 1e6+500;
int dp[50];
inline void solve(){
	IOS;
	dp[0]=dp[1]=1;
	for(int i=2 ; i<=45 ; ++i) dp[i]=dp[i-1]+dp[i-2];
		int n; cin >> n;
	cout << dp[n-2]+dp[n-3] << ':' << dp[n-1]+dp[n-2] << '\n';
}
signed main(){solve();}