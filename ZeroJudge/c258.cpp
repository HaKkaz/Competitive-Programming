#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
const int maxn = 5e5+50;
pii seg[maxn];
vector<int> disc;
int bit[maxn<<1];
void upd(int i , int k){
	for( ; i < maxn<<1 ; i += (i & (-i)))
		bit[i] += k;
}
int qry(int i){
	int res = 0 ; 
	for( ; i ; i -= (i & (-i)))
		res += bit[i];
	return res;
}
signed main(){
	IOS;
	int n; cin >> n ;
	for(int i=0 ; i<n ; ++i){
		int x , r;
		cin >> x >> r;
		seg[i].F = x-r , seg[i].S = x+r;
		disc.pb(x-r);
		disc.pb(x+r);
	}
	sort(all(disc)) , disc.resize(unique(all(disc)) - disc.begin());
	sort(seg , seg+n);
	for(int i=0 ; i<n ; ++i){
		seg[i].F = upper_bound(all(disc) , seg[i].F) - disc.begin();
		seg[i].S = upper_bound(all(disc) , seg[i].S) - disc.begin();
	}
	int ans = 0 ;
	for(int i=0 ; i<n ; ++i){
		ans += qry(seg[i].F-1);
		upd(seg[i].S , 1);
	}
	fill(bit , bit+(maxn<<1) , 0);
	for(int i=n-1 ; i>=0 ; --i){
		// vector<int> tmp;
		// tmp.push_back(seg[i].S);
		ans += qry(seg[i].S-1);
		upd(seg[i].S,1);
		/*while(i-1 >= 0 && seg[i].F == seg[i-1].F){
			tmp.push_back(seg[i].S);
			ans += qry(seg[i].S-1);
			--i;
		}
		for(int &c : tmp) upd(c , 1);*/
	}
	cout << ans << '\n';
}
//https://zerojudge.tw/ShowProblem?problemid=c258