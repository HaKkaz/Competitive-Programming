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
	int n, q, x; cin >> n >> q >> x;

	vector<int> p(n+1,0);
	for(int i=1 ; i<=n ; ++i){
		int w; cin >> w;
		p[i] = w + p[i-1];
	}

	vector<int> cnt(n);
	vector<int> pack;
	bitset<200050> vis;

	int l = 0 ;
	while(!vis[l]){
		vis[l] = true;
		pack.emplace_back(l);
		int goal = p[l] + x;
		int cys = goal / p[n];
		int remain = goal % p[n];
		auto r = n * cys + lower_bound(ALL(p) , remain) - p.begin();
		cnt[l] = r - l;
		l = (r + n) % n ;
	}

	int start = find(ALL(pack) , l) - pack.begin();
	int cylen = pack.size() - start;
	while(q--){
		int k ; cin >> k , --k;
		if(k >= start){
			k -= start;
			k %= cylen;
			k += start;
		}
		cout << cnt[pack[k]] << '\n';
	}
}