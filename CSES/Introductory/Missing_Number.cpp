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
    int n,x; cin >> n;
    vector<int> a(n+1,0);
    for(int i=1 ; i<n ; ++i) cin >> x , a[x] = 1;
    for(int i=1 ; i<=n ; ++i) if(!a[i]) cout << i << '\n';
}

