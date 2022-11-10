#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#define pb push_back
#define mp make_pair
#define Sz(x) (int)(x).size()
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
#define lowbit(x) (x&(-x))
#define int long long
const int maxn = 1e6+5;
int bit[maxn] , n , num[maxn] , dp[maxn];
vector<int> v ;
vector<pii> v2;
inline int maxx(int a, int b){
	if(a > b) return a;
	return b;
}
inline void init(){
	v.clear() , v2.clear();
	for(int i=0 ; i<100005; ++i) bit[i] = dp[i] = num[i] = 0;
}
inline void update(int x , int val){
	for(int i=x ; i<maxn ; i+=lowbit(i)){
		bit[i] = maxx(bit[i] , val);
	}
}
inline int query(int x){
	int mx = 0;
	--x;
	for(int i=x ; i ; i-=lowbit(i)) mx = maxx(mx , bit[i]);
	return mx;
}

inline void dec(){
	for(int i=1 ; i<=n ; ++i) cin >> num[i];
	for(int i=1 ; i<=n ; ++i) v.pb(num[i]);
	 sort(all(v)) , v.resize(unique(all(v))-v.begin());
	v2.pb({0 , 0});
	for(int i=1 ; i<=n ; ++i){
		int now = upper_bound(all(v) , num[i]) - v.begin();
		v2.pb({now , num[i]});															
	}
}

signed main(){__IO
	while(cin >> n){
		int mx = 0;
		init();
		dec();
		dp[1] = v2[1].S;
		update(v2[1].F , dp[1]);
		for(int i=2 ; i<=n ; ++i){
			int Q = query(v2[i].F);
			dp[i] = Q + v2[i].S;
			update(v2[i].F , dp[i]);
		}
		for(int i=1 ; i<=n ; ++i) mx = maxx(mx , dp[i]);
		cout << mx << '\n';
	}
}