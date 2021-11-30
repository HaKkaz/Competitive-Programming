#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define ft first
#define sd second
#define ALL(v) v.begin(),v.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 
const int maxn = 1e5+50;
int all_xo = 0 , a[maxn] , dp[maxn];
bool ok;
vector<int> v[maxn];
void dfs(int now , int fa){
   for(int &c : v[now]){
        if(c == fa) continue;
        dfs(c , now);
        a[now] ^= a[c];
        dp[now] += dp[c];
   }
   if(a[now] == all_xo && dp[now] == 0) dp[now]++;
   if(dp[now] >= 2) ok = true;
   if(a[now] == 0 && dp[now]) ok = true;
}

int main(){
	fast;
    int t; cin >> t;
    while(t--){
        int n , k ;
        cin >> n >> k ;
        all_xo = 0;
        for(int i=1 ; i<=n ; ++i) v[i].clear(), dp[i] = a[i] = 0;
        for(int i=1 ; i<=n ; ++i) cin >> a[i] , all_xo ^= a[i];
        ok = all_xo == 0;
        for(int i=1 ; i<n ; ++i)
        {
            int x,y; cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(all_xo != 0 && k-1 >= 2)dfs(1,0);
        cout << (ok ? "YES\n" : "NO\n") ; 
    }
}

