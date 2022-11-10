#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

int a[6],b[6],c[4];
signed main(){
	IOS;
	
	for(int i=0 ; i<3 ; ++i){
		cin >> c[i];
	}
	for(int i=0 ; i<5 ; ++i){
		cin >> a[i];
	}
	for(int i=0 ; i<5 ; ++i){
		cin >> b[i];
	}
	map<int,int> cnt;
	for(int i=0 ; i<5 ; ++i){
		cnt[a[i]] += b[i];
	}
	int ans = 0 ;
	for(int i=0 ; i<2 ; ++i){
		ans += cnt[c[i]];
	}
	if(cnt[c[2]]) ans = max(0ll,ans-cnt[c[2]]);
	else ans <<= 1;
	cout << ans << '\n';
}