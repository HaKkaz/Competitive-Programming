#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
// #define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;

const int maxn = 30005;
map<int,vector<pii>> vx,vy;

signed main(){
	fast;
	int n; cin >> n ;
	for (int i = 0; i < n; ++i) {
		int x, y, t;
		cin >> x >> y >> t;
		vx[x].emplace_back(y,t);
		vy[y].emplace_back(x,t);
	}
	for (int i = -30000; i <= 30000; ++i) {
		sort(ALL(vx[i]));
		sort(ALL(vy[i]));
	}

	int cur_x = 0, cur_y = 0;
	int dir = 1; // left(0), right(1), up(2), down(3)
	int ans = 0 ;

	while (true) {
		if (dir == 0) {//
			auto it = lower_bound(vy[cur_y].begin(), vy[cur_y].end(), make_pair(cur_x,-1));
			if (it == vy[cur_y].begin()) break;
			--it;
			if (it->second == 0) dir = 3;
			else dir = 2;
			cur_x = it->first;
		}
		else if (dir == 1) {//
			auto it = lower_bound(vy[cur_y].begin(), vy[cur_y].end(), make_pair(cur_x+1,-1));
			if (it == vy[cur_y].end()) break;
			if (it->second == 0) dir = 2;
			else dir = 3;
			cur_x = it->first;
		}
		else if (dir == 2) {
			auto it = lower_bound(vx[cur_x].begin(), vx[cur_x].end(), make_pair(cur_y+1,-1));
			if (it == vx[cur_x].end()) break;
			if (it->second == 0) dir = 1;
			else dir = 0;
			cur_y = it->first;
		}
		else if (dir == 3) {
			auto it = lower_bound(ALL(vx[cur_x]), make_pair(cur_y,-1));
			if (it == vx[cur_x].begin()) break;
			--it;
			if (it->second == 0) dir = 0;
			else dir = 1;
			cur_y = it->first;
		}
		++ans;
	}
	cout << ans << '\n';
}