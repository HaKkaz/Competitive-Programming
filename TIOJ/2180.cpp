#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
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
const int inf = 2e9;
int a[1005][1005] , dx[]={1,-1,0,0} , dy[]={0,0,1,-1};
bool vis[1005][1005];
signed main(){
	IOS;
	int n , m , sx , sy , ex , ey , k;
	cin >> n >> m >> sx >> sy >> ex >> ey;
	cin >> k;
	for(int i=0 ; i<n ; ++i)for(int j=0 ; j<m ; ++j) a[i][j]=inf;
	while(k--){
		int x,y; 
		cin >> x >> y;
		cin >> a[x][y];
	}
	a[sx][sy] = a[ex][ey] = 0;
	priority_queue<piii , vector<piii> , greater<piii> > q;
	q.push({a[sx][sy],{sx,sy}});
	while(q.size()){
		int val = q.top().F , x = q.top().S.F , y = q.top().S.S;
		q.pop();
		for(int i=0 ; i<4 ; ++i){
			int xx = x+dx[i] , yy = y+dy[i];
			if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy]){
				a[xx][yy] = max(a[xx][yy] , val);
				vis[xx][yy] = 1;
				q.push({a[xx][yy] , {xx , yy}});
			}
		}
	}
	cout << a[ex][ey] << '\n';
}