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

ll a[200050];
signed main(){
    fast;
    int n ; cin >> n ;

    for(int i=0 ; i<n ; ++i) cin >> a[i];
    sort(a , a + n);
    
    ll ans = 0;
    for(int i=0 ; i<n ; ++i){
        ans += labs(a[i] - a[n/2]) ;
    }
    cout << ans << '\n';
}
