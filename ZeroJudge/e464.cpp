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
inline void latina(){
	int r , n;
	while(cin >> r >> n){
		if(r == -1 and n == -1) break;
		vector<int> v;
		for(int i=0 ; i<n ; ++i){
			int x ; cin >> x;
			v.pb(x);
		}
		sort(all(v));
		int now = 0 , i = 0 , ans = 0;
		while(i < n){
			while(i<n and v[i] - v[now] <= r) ++i;
			now = i-1;
			while(i<n and v[i] - v[now] <= r) ++i;
			++ans;
			now = i;
		}
		cout << ans << '\n';
	}
}
signed main(){loli;latina();}