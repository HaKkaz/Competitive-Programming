#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int MAXN = 1005;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0} , n , m;
int a[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool check(int x , int y){//判斷(x,y)在不在座邊範圍內
    return (x>=1 && y>=1 && x<=n && y<=n);
}
void BFS(int sx ,int sy){
	int ans = 0;
    queue< pair<int,int> > q;
    q.push({sx , sy});
    vis[sx][sy] = 1;
    while(q.size()){
        int x = q.front().F , y = q.front().S;
        q.pop();
        ++ans;
        for(int i=0 ; i<4 ; ++i){
            int xx = x+dx[i] , yy = y+dy[i];
            if(check(xx , yy) && !vis[xx][yy] && abs(a[x][y] - a[xx][yy]) <= 2){
                q.push({xx , yy});
                vis[xx][yy] = 1;
            }
        }
    }
    cout << ans << '\n';
}
signed main(){
	IOS;
	cin >> n;
	int sx , sy ; cin >> sx >> sy;
	++sx , ++sy;
	for(int i=1 ; i<=n ; ++i) for(int j=1 ; j<=n ; ++j) cin >> a[i][j];
	BFS(sx,sy);
}