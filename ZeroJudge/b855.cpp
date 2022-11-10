#include"bits/stdc++.h"
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 1000005;
int dp[maxn];
vector<int> v;
inline void latina(){
	int t;  cin >> t;
	while(t--){
		int n , tot = 0; cin >> n;
		v.clear(),v.rz(n);
		for(int i=0 ; i<n ; ++i){
			cin >> v[i];
			tot += v[i];
		}
		int half = tot>>1;
		fill(dp , dp+half+1 , 0);
		for(int i=0 ; i<n ; ++i)
			for(int j=half ; j>=v[i] ; --j)
				dp[j] = max(dp[j] , dp[j-v[i]]+v[i]);
		cout << dp[half]*dp[half] + (tot-dp[half])*(tot-dp[half]) << '\n';
	}
}
signed main(){loli;latina();}