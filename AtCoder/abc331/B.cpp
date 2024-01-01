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

signed main() { fast;
    int n, s, m, l;
    cin >> n >> s >> m >> l;
    int ans = 1e9;
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            for (int k = 0; k <= 100; ++k) {
                if (6 * i + j * 8 + k * 12 >= n) {
                    ans = min(ans, i * s + j * m + k * l);
                }
            }
        }
    }
    cout << ans << '\n';
}
