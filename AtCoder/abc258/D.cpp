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

signed main(){
	fast;
	int n , x;
	cin >> n >> x;
	int ans = 4e18 , sum = 0 , mn_stage = 2e9; 
	for(int i=1 ; i<=n ; ++i){
		int a,b; cin >> a >> b;
		sum += a + b;
		mn_stage = min(mn_stage , b);
		ans = min(ans , 1ll * (x - i) * mn_stage + sum);
	}
	cout << ans << '\n';
}