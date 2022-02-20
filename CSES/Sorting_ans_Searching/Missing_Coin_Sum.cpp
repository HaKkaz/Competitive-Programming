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
    vector<ll> a(n);
    for(ll &x : a) cin >> x;
    
    sort(ALL(a));
    ll top = 0;
    for(int i=0 ; i<n ; ++i){
        if(a[i] > top+1){
            cout << top + 1 << '\n';
            return 0;
        }
        top += a[i];
    }
    cout << top + 1 << '\n';
}

//1 
//1 2 3
//1 2 3 4 5 6 
//1i

