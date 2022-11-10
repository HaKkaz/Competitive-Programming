#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 500001;
int dp[120];
inline void latina(){
	int n;
	while(cin >> n){
		fill(dp , dp+101 , 0);
		for(int i=0 ; i<n ; ++i){
			int w , p;
			cin >> w >> p;
			for(int j=100 ; j>=w ; --j)
				dp[j] = max(dp[j] , dp[j-w]+p);
		}
		cout << dp[100] << '\n';
	}
}
signed main(){loli;latina();}