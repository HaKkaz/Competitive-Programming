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
const int maxn = 5005;
vector<pii> v[maxn];
int ans , q , vk , n;
void dfs(int now , int last , int MN){
    if(MN >= q) ++ans;
    for(auto &c : v[now]){
        if(c.F != last){
            dfs(c.F , now , min(MN,c.S));
        }
    }
}
inline void latina(){
    loli;
    cin >> n >> vk >> q; 
    for(int i=1,a,b,w ; i<n ; ++i) cin >> a >> b >> w , v[a].pb({b,w}) , v[b].pb({a,w});
    dfs(vk , -1 , 1e12),--ans;
    cout << ans << '\n';
}
signed main(){latina();}