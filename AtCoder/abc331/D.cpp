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

signed main() { 
    // fast;
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    for (auto &row : s) cin >> row;

    vector< vector<int> > pre(n+1, vector<int>(n+1,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1] + (s[i-1][j-1] == 'B');
        }
    }

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ++a, ++b, ++c, ++d;
        int aa = a, bb = b;
        int cc = c, dd = d;
        c -= (a-1), a = 1;
        d -= (b-1), b = 1;
        cout << "a b c d" _ a _ b _ c _ d << endl;
        
        int Lx = c%n, Ly = d/n*n, Lc = d/n;
        int Tx = c/n*n, Ty = d%n, Tc = c/n;
        int LB = pre[c % n + cc % n][n] - pre[aa % n + 1][n];
        cout << "LB" _ LB << endl;
        LB *= Lc;

        int TB = (dd % n > bb % n) ? 
            pre[n][dd % n + 1] - pre[n][bb % n + 1]:
            pre[n][bb % n + 1] - pre[n][dd % n + 1];
        cout << "TB" _ TB << endl;
        TB *= Tc;

        cout << "Lc" _ Lc << endl;
        cout << "Tc" _ Tc << endl;
        
        int ans = pre[n][n] * (c/n) * (d/n) + LB + TB ;
        // cout << "pre[n][n]" _ pre[n][n] << endl;
        // cout << "(c/n) * (d/n)" _ c/n * d/n << endl;
        // cout << "LB" _ LB _ "TB" _ TB << endl;
        cout << ans << '\n';
    }
}
