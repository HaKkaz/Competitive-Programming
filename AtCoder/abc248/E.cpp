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
	int n,k;
	cin >> n >> k;
	if(k == 1){
		cout << "Infinity\n";
		return 0;
	}
	vector<pii> pts(n);
	for(auto &[x,y] : pts){
		cin >> x >> y;
	}

	set< pair<pii,pii> > lines;

	int ans = 0;
	for(int i=0 ; i<n ; ++i){
		map<pii , vector<pii> > cnt;
		auto [x,y] = pts[i];
		for(int j=0 ; j<n ; ++j){
			auto [xx,yy] = pts[j];
			int dx = x - xx;
			int dy = y - yy;
			if(dx == 0 && dy == 0) continue;
			if(dx != 0 && dy != 0){
				int gcd = __gcd(dx,dy);
				dx /= gcd;
				dy /= gcd;
			}
			// cout << dx << ' ' << dy << '\n';
			if(dx == 0) dy = 2e9;
			if(dy == 0) dx = 2e9;
			if(1LL * dx * dy > 0) dx = abs(dx) , dy = abs(dy);
			if(1LL * dx * dy < 0) dx = -abs(dx) , dy = abs(dy);
			cnt[{dx,dy}].emplace_back(xx,yy);
		}
		for(auto it : cnt){
			auto v = it.sd;
			v.emplace_back(x,y);
			if((int)v.size() < k) continue;
			sort(ALL(v));
			auto p = make_pair(v.front(),v.back());
			if(lines.find(p) == lines.end()) ++ans,lines.emplace(p);
		}
	}
	cout << ans << '\n';
}