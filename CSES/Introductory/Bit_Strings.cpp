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

    const int mod = 1e9+7;
    ll ans = 1 , a = 2;
    for( ; n ; n>>=1 , a = a * a % mod)
        if(n & 1)
            ans = ans * a % mod;
    cout << ans << '\n';
}

