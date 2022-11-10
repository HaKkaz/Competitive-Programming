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
const int maxn = 2e5+50;
int dp[maxn] , a[maxn] , n;
inline void init(){
	for(int i=0 ; i<=n ; ++i) dp[i] = 0;
}
inline void solve(){
	int n; cin >> n ;
	for(int i=1 ; i<=n ; ++i) cin >> a[i];
	cout << a[1] << ' ';
	for(int i=2 ; i<=n ; ++i) cout << a[i]-a[i-1]<<' ';
}
signed main(){IOS;solve();}