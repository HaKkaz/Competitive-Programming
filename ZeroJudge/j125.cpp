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

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

signed main(){
	fast;
	int n; cin >> n ;

	vector< vector<int> > h(n , vector<int>(n));
	for(int i=0 ; i<n ; ++i)
		for(int j=0 ; j<n ; ++j)
			cin >> h[i][j];

	int l=0,r=1000000;
	int ans_dis = -1;
	while(l < r){
		int mid = (l+r)/2;
		// BFS
		vector< vector<bool> > vis(n , vector<bool>(n,false));
		vector< vector<int> >  dis(n , vector<int>(n,0));
		queue<pii> q;
		q.emplace(0,0);
		vis[0][0] = true;
		bool ok = false;
		while(q.size()){
			auto [x,y] = q.front();
			q.pop();
			if(x == n-1 && y == n-1) ok = true;
			for(int i=0 ; i<4 ; ++i){
				int xx = x + dx[i];
				int yy = y + dy[i];
				if(xx >= 0 && xx < n && yy >= 0 && yy < n && abs(h[xx][yy] - h[x][y]) <= mid && !vis[xx][yy]){
					q.emplace(xx,yy);
					vis[xx][yy] = true;
					dis[xx][yy] = dis[x][y] + 1;
				}
			}
		}
		if(!ok) l = mid+1;
		else r = mid , ans_dis = dis[n-1][n-1];
	}
	cout << l << '\n';
	cout << ans_dis << '\n';
}