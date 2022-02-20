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
    int x , n ; cin >> x >> n ;

    set<int> st;
    multiset<int> seg;

    st.insert(0);
    st.insert(x);
    seg.insert(x);

    for(int i=0 ; i<n ; ++i){
        int cut; cin >> cut;
        auto it = st.upper_bound(cut);
        int r = *it;
        int l = *prev(it);

        seg.erase(seg.find(r-l));
        seg.insert(r-cut);
        seg.insert(cut-l);

        st.insert(cut);

        cout << *seg.rbegin() << ' ';
    }
}

