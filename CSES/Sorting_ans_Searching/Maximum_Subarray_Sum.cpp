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

signed main(){
    fast;
    int n; cin >> n;
    ll ans = -1e18 , MN = 0 , pre = 0;
    for(int i=0 ; i<n ; ++i){
        ll x; cin >> x;
        pre += x;
        ans = max(ans , pre - MN);
        MN = min(MN , pre);
    }
    cout << ans << '\n';
}

