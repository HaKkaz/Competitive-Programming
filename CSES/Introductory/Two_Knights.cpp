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
    int n ; cin >> n;
    for(ll i=1 ; i<=n ; ++i){
        ll ans = i*i * (i*i-1) / 2;
        ll dec = (i-1) * (i-2) * 4;
        cout << ans - dec << '\n';
    }
    
}

