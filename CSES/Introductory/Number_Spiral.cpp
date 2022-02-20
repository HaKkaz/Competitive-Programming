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
    int q; cin >> q;
    while(q--){
        int x , y; cin >> x >> y;
        ll mx = max(x,y)-1;
        ll step = min(x,y);
        ll ans = mx * mx;

        if(x >= y){
            if(x & 1) ans += step;
            else ans += mx*2+1 - step+1;
            cout << ans;
        }
        else{
            if(y & 1) ans += mx*2+1-step+1;
            else ans += step;
            cout << ans;
        }

        cout << '\n';
    }

}

