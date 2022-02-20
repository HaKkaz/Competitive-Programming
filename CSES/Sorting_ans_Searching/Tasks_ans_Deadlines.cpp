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
    int n; cin >> n ;
    vector< pii > v(n);
    for(auto &[a,d] : v) cin >> a >> d;    

    sort(ALL(v));
    ll step = 0 , now = 0 , sum = 0;
    
    for(int i=0 ; i<n ; ++i){
        auto &[a,d] = v[i];
        now += a;
        sum += d;
        step += now;
    }

    cout << sum - step << '\n';

}

