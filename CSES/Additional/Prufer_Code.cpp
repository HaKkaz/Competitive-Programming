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
    vector<int> a(n-2);
    vector<int> cnt(n+1,0);
    set<int> s;
    for(int i=n-3 ; i>=0 ; --i) cin >> a[i] , cnt[a[i]]++;
    for(int i=1 ; i<=n ; ++i) if(cnt[i] == 0) s.insert(i);

    // for(auto c : s) cout << c << ' ' ;

    while(a.size()){
        int x = *s.begin();
        int y = a.back();
        a.pop_back();
        s.erase(x);
        cnt[y]--;
        if(cnt[y] == 0) s.insert(y);
        cout << x << ' ' << y << '\n';
    }
    int x = *s.begin();
    int y = *next(s.begin());
    cout << x << ' ' << y << '\n';
}

