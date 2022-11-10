#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 100005;
vector<int> v[maxn];
bool tag = 1;
int ans[2] , n , color[maxn] , sum;
bitset<maxn> vis;
void dfs(int now , int col){
    vis[now] = 1;
    color[now] = col;
    ans[col]++;
    for(auto &c : v[now]){
        if(!vis[c]){
            dfs(c , 1-col);
        }
        else if(color[c] != 1-col){
            tag=0;
            return;
        }
    }
}
inline void latina(){
    loli;
    int n , m ;
    cin >> n >> m; 
    for(int i=0,a,b ; i<m ; ++i) cin >> a >> b , v[a].pb(b) , v[b].pb(a);
    for(int i=1 ; i<=n ; ++i){
        if(!vis[i]){
            ans[0]=ans[1]=0;
            dfs(i , 0);
            sum += min(ans[0],ans[1]);
        }
    }
    if(tag)cout << sum << '\n';
    else cout << 0 << '\n';
}
signed main(){latina();}