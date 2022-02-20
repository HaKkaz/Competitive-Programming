#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(1);else cerr
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

int ans = 0;
bool vis[7][7];
string s;

bool in(int x , int y){
    return x>=0 and x<7 and y>=0 and y<7 and !vis[x][y];
}


void dfs(int x , int y , int i){
    vis[x][y] = 1;
    if(x == 6 and y == 0){
        if(i == 47) ++ans;
        vis[x][y] = 0;
        return;
     

    if((s[i] == 'L' or s[i] == '?') and in(x,y-1)) dfs(x,y-1,i+1);
    if((s[i] == 'R' or s[i] == '?') and in(x,y+1)) dfs(x,y+1,i+1);
    if((s[i] == 'U' or s[i] == '?') and in(x-1,y)) dfs(x-1,y,i+1);
    if((s[i] == 'D' or s[i] == '?') and in(x+1,y)) dfs(x+1,y,i+1);

    vis[x][y] = 0;
}

signed main(){
    fast;
    cin >> s;
    dfs(0,0,0);
    cout << ans << '\n';
}

