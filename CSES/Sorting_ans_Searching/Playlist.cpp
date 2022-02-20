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

int cnt[200050];

signed main(){
    fast;
    int n; cin >> n;
    vector<int> a(n) , dec;
    for(int &x : a) cin >> x;
    dec = a , sort(ALL(dec)) , dec.resize(unique(ALL(dec)) - dec.begin());

    int ans = 0 , top = 0;
    for(int i=0 ; i<n ; ++i){
        a[i] = lower_bound(ALL(dec) , a[i]) - dec.begin();
        while(cnt[a[i]]) --cnt[a[top]] , ++top;
        cnt[a[i]]++;
        ans = max(ans , i - top + 1);
    }
    cout << ans << '\n';
}

