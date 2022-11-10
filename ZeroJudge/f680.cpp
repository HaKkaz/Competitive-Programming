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
bool vis[20][20];
int a[20][20],n,ans,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
void BFS(int sx , int sy){
    ++ans;
    queue<pii> q;
    q.push({sx,sy});
    vis[sx][sy] = 1;
    while(q.size()){
        int x=q.front().F,y=q.front().S;
        q.pop();
        for(int i=0;i<4;++i){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < n && a[xx][yy]==a[sx][sy] && !vis[xx][yy]){
                q.push({xx,yy});
                vis[xx][yy]=1;
            }
        }
    }
}
signed main(){
    IOS;
    cin >> n ;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>a[i][j];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(!vis[i][j] && a[i][j]){
                BFS(i,j);
            }
    cout << ans << '\n';
}