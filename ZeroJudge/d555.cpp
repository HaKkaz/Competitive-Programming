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
	for(int kase=1,n ; cin >> n ; ++kase){
		vector<pii> v;
		for(int i=1 ; i<=n ; ++i){
			int x,y; cin >> x >> y;
			v.push_back({x,y});
		}
		sort(all(v) , greater<pii>());
		vector<pii> ans;
		int mx=-1e9;
		for(int i=0 ; i<n ; ++i){
			if(mx < v[i].S) ans.pb(v[i]);
			mx = max(mx , v[i].S);
		}
		sort(all(ans));
		cout << "Case " << kase << ": \n";
		cout << "Dominate Point: "<< SZ(ans) <<" \n";
		for(pii &c : ans) cout << '('<< c.F << ',' << c.S <<')' << '\n';
	}
}