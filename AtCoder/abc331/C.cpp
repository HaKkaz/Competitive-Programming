#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#include<bits/stdc++.h>
#define int long long
using namespace std;
#ifdef DEBUG
#define fast
#else
#define fast cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define cerr if(1); else cerr
#endif
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

signed main() { fast;
    int n; cin >> n ;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> b(a);
    sort(ALL(b));
    vector<int> c(b);

    for (int i = n-2; i >= 0; --i) {
        c[i] += c[i+1];
    }

    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(ALL(b), a[i]);
        int idx = it - b.begin();
        if (idx == n) cout << 0 << ' ';
        else cout << c[idx] << ' ';
    }
}
