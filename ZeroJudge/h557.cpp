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

unordered_map<int,bool> cnt;

signed main(){
	fast;
	int n,r;
	cin >> n >> r;
	for(int i=0 ; i<n ; ++i){
		int x,y; cin >> x >> y;
		for(int yy=y-r ; yy<=y+r ; ++yy){
			for(int xx = x ; xx>=x-r ; --xx){
				if((xx-x)*(xx-x) + (yy-y)*(yy-y) <= r*r){
					cnt[(xx<<30) + yy]^=1;
				}
				else break;
			}
			for(int xx = x+1 ; xx<=x+r ; ++xx){
				if((xx-x)*(xx-x) + (yy-y)*(yy-y) <= r*r){
					cnt[(xx<<30) + yy]^=1;
				}
				else break;
			}
		}
	}
	int ans = 0 ;
	for(auto &it : cnt){
		ans += it.sd;
	}
	cout << ans << '\n';
}