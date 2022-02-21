#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define all(x) (x).begin() , (x).end()
using namespace std;
const int inf = 4e18;
const int maxn = 5005;
vector<pair<pii,int> > v;
int mn[maxn];
int pow2(int x){
	return x*x;
}
int dis(pair<pii,int> a , pair<pii,int> b){
	int x1 = a.F.F , y1 = a.F.S , z1 = a.S;
	int x2 = b.F.F , y2 = b.F.S , z2 = b.S;
	return pow2(x1-x2) + pow2(y1-y2) + pow2(z1-z2);
}
bitset<maxn> vis;
int ans = 0;
signed main(){
	int n; cin >> n ;
	v.resize(n+1);
	for(int i=1 ; i<=n ; ++i){
		cin >> v[i].F.F >> v[i].F.S >> v[i].S;
	}
	fill(mn , mn+n+1 , inf);
	mn[1] = 0;
	for(int i=1 ; i<=n ; ++i){
		int MN = inf , nxt = -1;
		for(int j=1 ; j<=n ; ++j){
			if(mn[j] < MN && !vis[j]) MN = mn[j] , nxt = j;
		}
		ans += MN;
		vis[nxt] = 1;
		for(int j=1 ; j<=n ; ++j){
			mn[j] = min(mn[j] , dis(v[nxt] , v[j]));
		}
	}
	cout << ans << '\n';
}