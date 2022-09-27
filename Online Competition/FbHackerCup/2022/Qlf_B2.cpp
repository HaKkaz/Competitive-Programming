#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
#ifndef DEBUG
#define fast cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define cerr if(1); else cerr
#endif
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;



inline inside(int x , int y , int n , int m){
	return x >= 0 && x <= n+1 && y >= 0 && y <= m+1;
}
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

inline void solve(){
	int n,m; cin >> n >> m ;
	vector< vector<char> > arr(n+2 , vector<char>(m+2,'#'));
	vector< vector<int> > rock(n+2 , vector<int>(m+2,0));

	function<bool(int,int)> ok = [&](int tx , int ty){
		int cnt=0;
		for(int d=0 ; d<4 ; ++d){
			int n_x = tx + dx[d];
			int n_y = ty + dy[d];
			cnt += (inside(n_x,n_y,n,m) && !rock[n_x][n_y]);
		}
		return cnt >= 2;
	};

	bool have_tree = false;

	for(int i=1 ; i<=n ; ++i){
		for(int j=1 ; j<=m ; ++j){
			cin >> arr[i][j];
			have_tree |= (arr[i][j] == '^');
		}
	}

	queue< pii > q;
	for(int i=0 ; i<=n+1 ; ++i){
		for(int j=0 ; j<=m+1 ; ++j){
			if(arr[i][j] == '#') q.emplace(i,j) , rock[i][j] = 1;
		}
	}

	string ans = "Possible";
	while(q.size()){
		auto [x,y] = q.front();
		q.pop();
		for(int i=0 ; i<4 ; ++i){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(!inside(xx,yy,n,m)) continue;

			int OK = ok(xx,yy);
			if(arr[xx][yy] != '#' && !rock[xx][yy] && !OK){
				if(arr[xx][yy] == '^') ans = "Impossible";
				q.emplace(xx,yy);
				rock[xx][yy]=1;
			}
		}
	}

	cout << ans << '\n';
	if(ans[0] == 'P'){
		for(int i=1 ; i<=n ; ++i){
			for(int j=1 ; j<=m ; ++j){
				if(have_tree) cout << (rock[i][j] ? arr[i][j] : '^');
				else cout << arr[i][j];
			}
			cout << '\n';
		}
	}

}

int main(){
	fast;
	freopen("second_second_friend_input.txt","r",stdin);
	freopen("second_second_friend_output.txt","w",stdout);
	int t; cin >> t;
	for(int Case=1 ; Case<=t ; ++Case){
		cout << "Case #" << Case << ": ";
		solve();
	}
}

/*
^^^#
^#^#
^^^^
^^^^
*/