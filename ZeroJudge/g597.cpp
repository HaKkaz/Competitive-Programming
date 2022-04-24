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
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
signed main(){
	IOS;
	int n , m ;
	cin >> n >> m ;
	vector< int > add(n+1 , 0);
	while(m--){
		int l , r , w; cin >> l >> r >> w;
		add[l] += w;
		add[r+1] -= w;
	}
	for(int i=1 ; i<=n ; ++i) add[i] += add[i-1];
	vector< int > a(n) , b(n);
	for(int &x : a) cin >> x;
	for(int i=0 ; i<n ; ++i) b[i] = add[i+1];
	sort(all(a));
	sort(all(b) , greater<int>());
	int ans = 0 ;
	for(int i=0 ; i<n ; ++i){
		ans += a[i] * b[i];
	}
	cout << ans << '\n';
}