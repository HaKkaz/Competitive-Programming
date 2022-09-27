#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
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

const int mod = 1e9+7;

ll calc(ll N , ll x , ll p , ll p2){
	ll ret = ((N*x%mod*x%mod - 2*x%mod*p%mod + mod) % mod + p2 )% mod;
	return ret % mod;
}

ll solve(){
	int n; cin >> n ;
	vector< vector<ll> > tree(2 , vector<ll>(n+1,0));
	ll tree_sum[] = {0LL,0LL};
	ll tree_pow[] = {0LL,0LL};

	for(int i=1 ; i<=n ; ++i){
		for(int k=0 ; k<2 ; ++k){
			cin >> tree[k][i];
			tree_sum[k] = (tree_sum[k] + tree[k][i]) % mod;
			tree_pow[k] = (tree_pow[k] + tree[k][i] * tree[k][i] % mod) % mod;
		}
	}

	int m; cin >> m;
	ll ans = 0 ; 
	for(int i=0 ; i<m ; ++i){
		for(int k=0 ; k<2 ; ++k){
			ll XY;
			cin >> XY;
			ans = (ans + calc(n , XY , tree_sum[k] , tree_pow[k]) % mod) % mod;
		}
	}

	return ans;
}

signed main(){
	fast;
	int t=1;
	cin >> t;
	for(int kase=1 ; kase<=t ; ++kase){
		cout << "Case #" << kase << ": " << solve() << '\n';
	}
}