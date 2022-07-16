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

struct Circle{
	int x , y , r;
	Circle(int _x , int _y , int _r):x(_x) , y(_y) , r(_r){}
	Circle(){}
};

int Distance(int x , int y , int xx , int yy){
	return (x - xx) * (x - xx) + (y - yy) * (y - yy);
}

signed main(){
	fast;
	int t=1;
	// cin >> t;
	while(t--){
		int n ; cin >> n ;
		int stx , sty, edx , edy;
		cin >> stx >> sty >> edx >> edy;
		vector< Circle > cs(n);
		for(auto &[x,y,r] : cs) cin >> x >> y >> r;

		bitset<3005> vis;
		vis.reset();

		queue< int > q;
		for(int i=0 ; i<n ; ++i){
			auto &[x,y,r] = cs[i];
			if(Distance(x , y , stx , sty) == r * r){
				q.emplace(i);
				vis[i] = 1;
			}
		}

		string ans = "No";

		while(q.size()){
			int now = q.front();
			q.pop();
			auto [x,y,r] = cs[now];

			if(Distance(x,y,edx,edy) == r*r){
				ans = "Yes";
				break;
			}

			for(int i=0 ; i<n ; ++i){
				if(vis[i]) continue;
				auto [xx,yy,rr] = cs[i];
				int Dis = Distance(x,y,xx,yy);
				if((r - rr) * (r - rr) <= Dis && Dis <= (r + rr) * (r + rr)){
					q.emplace(i);
					vis[i] = 1;
				}
			}
		}

		cout << ans << '\n';
	}
}