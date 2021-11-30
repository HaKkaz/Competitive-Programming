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
const int maxn = 505;
vector<int> G[maxn];
array<int,maxn> mp;
bitset<maxn> vis;

bool dfs(int u){
    vis[u] = 1;
    for(int v : G[u]){
        if(mp[v] == -1 || (!vis[mp[v]] && dfs(mp[v]))){
            return mp[v] = u , true;
        }
    }
    return false;
}


signed main(){
	fast;

    int n; cin >> n ;
    vector<string> a(n);
    for(int i=0 ; i<n ; ++i) cin >> a[i];

    int len=a[0].size();

    for(int i=0 ; i<n ; ++i){
        for(int j=i+1 ; j<n ; ++j){
            int cnt=0;
            for(int k=0 ; k<len ; ++k){
                if(a[i][k] != a[j][k]) ++cnt;
            }
            if(cnt == 2){
                G[i].emplace_back(j);
                G[j].emplace_back(i);
            }
        }
    }

    mp.fill(-1);
    int ans = 0 ;
    for(int i=0 ; i<n ; ++i){
        int cnt = 0 ;
        for(int x=0 ; x<len ; ++x){
            for(int y=x+1 ; y<len ; ++y){
                if(a[i][x] > a[i][y]) ++cnt;
            }
        }
        if(cnt & 1){
            if(vis.reset() , dfs(i)) ++ans;
        }
    }

    cout << n - ans << '\n';
    ;
}

