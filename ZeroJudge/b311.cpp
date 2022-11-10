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
const int mod = 100000007;
const int maxn = 500001;
vector<pii> v;
int n , a , b;
bool cmp(const pii &a , const pii &b){
	return a.F*b.S < a.S*b.F;
}
inline void latina(){
	cin >> n ;
	for(int i=0 ; i<n ; ++i){
		cin >> a >> b;
		if(a or b)v.push_back({a , b});
	}
	sort(all(v),cmp);
	int now = 0 , ans = 0;
	for(auto &c : v){
		ans += (now*c.S + c.F) , ans%=mod;
		now = ans , now%=mod;
	}
	cout << ans << '\n';
}
signed main(){loli;latina();}