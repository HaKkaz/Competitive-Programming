#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#include<bits/stdc++.h>
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

int main() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> p(n-1), t(n-1);
    
    int lcm = 1;
    for (int i = 0; i < n-1; ++i) {
        cin >> p[i] >> t[i];
        lcm = lcm * p[i] / __gcd(lcm, p[i]);
    }

    vector<ll> ans(841);
    for (int i = 0; i < lcm; ++i) {
        ll cur = i + x;
        for (int j = 0; j < n-1; ++j) {
           cur = 1LL * (cur + p[j] - 1) / p[j] * p[j]; 
           cur += t[j];
        }
        cur += y;
        ans[i] = cur;

    }

    int Q; cin >> Q;
    while(Q--) {
        int q; cin >> q;
        int st = q % lcm;
        int base = q - st;
        cout << ans[st] + base << '\n';
    }
}
