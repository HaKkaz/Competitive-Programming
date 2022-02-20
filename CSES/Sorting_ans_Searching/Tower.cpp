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
    multiset<int> mst;
    for(int i=0 ; i<n ; ++i){
        int x; cin >> x;
        auto it = mst.upper_bound(x);
        if(it != mst.end()){
            mst.erase(it);
        }
        mst.insert(x);
    }
    cout << mst.size() << '\n';
}

