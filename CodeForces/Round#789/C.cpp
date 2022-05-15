#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define int long long
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

const int MAXN = 5005;
int bit[2][MAXN];
void upd(int i , int k , int id){
	for( ; i<MAXN ; i += (i & -i))
		bit[id][i] += k;
}

int qry(int i , int id){
	int ret = 0 ;
	for( ; i ; i -= (i & -i))
		ret += bit[id][i];
	return ret;
}

void solve(){
	int n;  cin >> n ;
	vector<int> v(n);
	for(int &x : v) cin >> x;
	int ans = 0;
	for(int i=0 ; i<=n ; ++i) bit[0][i] = 0;
	for(int b=1 ; b<n-2 ; ++b){
		upd(v[b-1] , 1 , 0);

		//right side values
		for(int i=0 ; i<=n ; ++i) bit[1][i] = 0;
		for(int d=b+1 ; d<n ; ++d){
			upd(v[d] , 1 , 1);
		}

		for(int c=b+1 ; c<n ; ++c){
			upd(v[c] , -1 , 1);
			int L = qry(v[c] , 0);
			int R = qry(v[b] , 1);
			ans += L * R;
		}
	}
	cout << ans << '\n';
}

signed main(){
	fast;
	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
}