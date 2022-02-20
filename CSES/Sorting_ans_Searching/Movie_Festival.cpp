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
    int n ; cin >> n ;
    vector<pii> v(n);
    for(auto &[l,r] : v) cin >> l >> r;

    sort(ALL(v));


    int ans = 0 , mnr = -1;
    for(auto [l,r] : v){
        // cout << mnr << ' ' << l << endl;
        if(mnr > l) mnr = min(mnr , r);
        else ++ans , mnr = r;
    }
    cout << ans << '\n';
}

