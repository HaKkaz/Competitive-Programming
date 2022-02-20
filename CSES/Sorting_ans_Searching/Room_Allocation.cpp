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
    int n; cin >> n;
    vector< tuple<int,int,int> > v(n);
    int cnt=0;
    for(auto &[l,r,id] : v) cin >> l >> r , id = cnt++;

    sort(ALL(v));

    vector<int> ans(n,0);
    priority_queue< pii > pq;
    set<int> s;
    for(int i=1 ; i<=n ; ++i) s.insert(s.end() , i);

    for(int i=0 ; i<n ; ++i){
        auto [l,r,id] = v[i];
        while(pq.size() and -pq.top().ft < l){
            s.insert(ans[pq.top().sd]);
            pq.pop();
        }
        pq.emplace(-r,id);
        ans[id] = *s.begin();
        s.erase(s.begin());
    }

    cout << *max_element(ALL(ans)) << '\n';
    for(int i=0 ; i<n ; ++i){
        cout << ans[i] << ' ';
    }
}

