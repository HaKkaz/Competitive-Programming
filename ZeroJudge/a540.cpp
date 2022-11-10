#include<bits/stdc++.h>
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
using namespace std;
const int inf = numeric_limits<int>::max();
const int maxn = 1e4+500;
int dp[maxn] , a[maxn] , n;
inline void init(){
	for(int i=0 ; i<=n ; ++i) dp[i] = 0;
}
inline void solve(){
	while(cin >> n and n){
		init();
		int ans = 0;
		for(int i=0 ; i<n ; ++i) cin >> a[i];
		dp[0] = max(a[0] , 0);
		for(int i=1 ; i<n ; ++i){
			if(dp[i-1]+a[i] >= 0) dp[i] = dp[i-1]+a[i];
			else dp[i] = max(a[i] , 0);
			ans = max(ans , dp[i]);
		}
		cout << (ans?"The maximum winning streak is "+to_string(ans)+".\n":
			"Losing streak.\n");
	}
}
signed main(){IOS;solve();}