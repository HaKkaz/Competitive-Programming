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
int dis[59][50] , dx[]={1,-1,0,0} , dy[]={0,0,1,-1} , n , m;
bool vis[50][50];
char mp[100][100];
bool check(int x , int y){
	return x>=1 && x<=n && y>=1 && y<=m && !vis[x][y] && mp[x][y] == '.';
}
signed main(){
	IOS;
	cin >> n >> m; 
	for(int i=1 ; i<=n ; ++i)for(int j=1 ; j<=m ; ++j) cin >> mp[i][j];
	queue<pii> q;
	q.push({1,1});
	vis[1][1] = 1;
	while(q.size()){
		int x = q.front().F , y = q.front().S;
		q.pop();
		if(x == n && y == m) {
			cout << dis[n][m] << '\n';
			return 0;
		}
		for(int i=0 ; i<4 ; ++i){
			int xx = x+dx[i] , yy = y+dy[i];
			if(check(xx,yy) && !vis[xx][yy]){
				q.push({xx , yy});
				vis[xx][yy] = 1;
				dis[xx][yy] = dis[x][y] + 1;
			}
		}
	}
	cout << -1 << '\n';
}