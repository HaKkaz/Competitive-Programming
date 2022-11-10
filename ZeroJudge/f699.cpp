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
int a[105][105];
int dis[105][105];
bool vis[105][105];
int dx[]={0 , 0 , 1 , -1};
int dy[]={1 , -1 , 0 , 0};
signed main(){
	IOS;
	int n , m;
	cin >> n >> m ;
	for(int i=1 ; i<=n ; ++i)for(int j=1 ; j<=m ; ++j) cin >> a[i][j];
	queue<pii> q;
	if(a[1][1] != 2) q.push({1,1}) , vis[1][1] = 1;
	bool ok = 0;
	while(q.size()){
		int x = q.front().F , y = q.front().S;
		q.pop();
		if(a[x][y] == 1) cout << dis[x][y] << '\n' , ok = 1;
		for(int i=0 ; i<4 ; ++i){
			int xx = x + dx[i] , yy = y + dy[i];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy] && a[xx][yy] != 2){
				q.push({xx , yy});
				dis[xx][yy] = dis[x][y] + 1;
				vis[xx][yy] = 1;
			}
		}
	}
	if(!ok) cout << "嘉油！\n";
}