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
    int n,x;
    cin >> n >> x;
    vector< pii > a(n);
    for(int i=0 ; i<n ; ++i){
        cin >> a[i].ft;
        a[i].sd = i+1;
    }
    sort(ALL(a));
    vector< pii > b;
    for(int i=0 ; i<n ; ++i){
        if(x - a[i].ft <= 0) break;
        auto it = lower_bound(ALL(b) , make_pair(x - a[i].ft,-1) );
        if(it != b.end() and it->ft == x-a[i].ft){
            cout << a[i].sd << ' ' << it->sd << '\n';
            return 0;
        }
        b.emplace_back(a[i]);
    }
    cout << "IMPOSSIBLE";
}

