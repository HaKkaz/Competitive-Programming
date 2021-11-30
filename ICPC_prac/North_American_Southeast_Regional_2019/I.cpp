#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long ;
using ld = long double ;
using pii = pair<int,int> ;
char a[2005][2005];
bool vis[2005][2005];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n2 , m2;

void BFS(int sx , int sy){
    queue<pii> q;
    q.emplace(sx,sy);
    vis[sx][sy] = 1;
    while(q.size()){
        auto [x,y] = q.front();
        q.pop();
        for(int i=0 ; i<4 ; ++i){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || xx > n2 || yy < 0 || yy > m2) continue;
            if(!vis[xx][yy] and a[xx][yy] == '.'){
                q.emplace(xx,yy);
                vis[xx][yy] = 1;
            }
        }
    }
}

signed main(){
	fast;

    int n , m; cin >> n >> m;
    n2 = n*2 + 3;
    m2 = m*2 + 3;

    for(int i=0 ; i<=n2 ; ++i)for(int j=0 ; j<=m2 ; ++j) a[i][j] = '.';

    for(int i=2 ; i<=n*2 ; i+=2){
        for(int j=2 ; j<=m*2 ; j+=2){
            cin >> a[i][j];
        }
    }

    for(int i=2 ; i<=n*2 ; i+=2){
        for(int j=2 ; j<=m*2 ; j+=2){
            if(a[i][j] == '\\') a[i+1][j+1] = a[i-1][j-1] = '\\';
            if(a[i][j] == '/' && a[i+2][j-2] == '/') a[i+1][j-1] = '/';
        }
    }

    int ans = 0 ;
    for(int x=0 ; x<n2 ; ++x){
        for(int y=0 ; y<m2 ; ++y){
            if(!vis[x][y] && a[x][y] == '.'){
                ++ans , BFS(x,y);
            }
        }
    }

    cout << ans-1 << '\n';
}

