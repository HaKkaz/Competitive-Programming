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
// #define int long long

using ll = long long;
using ld = long double;
using pii = pair<int,int>;

signed main(){
    fast;
    int n , x; cin >> n >> x;
    vector<int> a(n);
    multiset< pii > mst;
    random_shuffle(ALL(a));
    for(int i=0 ; i<n ; ++i){
        cin >> a[i];
        mst.emplace(a[i] , i);
    }

    for(int i=0 ; i<n ; ++i){
        mst.erase(mst.find(pii(a[i],i)));
        for(int j=i+1 ; j<n ; ++j){
            mst.erase(mst.find( make_pair(a[j],j) ));
            auto it = mst.lower_bound( make_pair(x-a[i]-a[j],-1) );
            if(it != mst.end() and it->first == x-a[i]-a[j]){
                cout << i+1 << ' ' << j+1 << ' ' << it->second+1 << '\n';
                return 0;
            }
            mst.emplace(a[j] , j);
        }
    }
    cout << "IMPOSSIBLE";
}

