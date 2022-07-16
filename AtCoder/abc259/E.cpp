#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
// #define int long long
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
	int t=1;
	// cin >> t;
	while(t--){
		int n; cin >> n ;
		vector< vector<pii> > v(n);
		map<int,pii> mx; // p , mx , cnt
		for(int i=0 ; i<n ; ++i){
			int m; cin >> m;
			v[i].resize(m);
			for(auto &[x,y] : v[i]){
				cin >> x >> y;
				if(mx[x].ft == y) mx[x].sd++;
				else if(mx[x].ft < y) mx[x].ft = y , mx[x].sd = 1;
			}
		}

		set< vector<int> > st;
		for(int i=0 ; i<n ; ++i){
			vector<int> tmp;
			for(auto [x,y] : v[i]){
				if(mx[x].ft == y && mx[x].sd == 1){
					tmp.emplace_back(x);
				}
			}
			st.emplace(tmp);
		}
		cout << st.size()<< '\n';

	}
}