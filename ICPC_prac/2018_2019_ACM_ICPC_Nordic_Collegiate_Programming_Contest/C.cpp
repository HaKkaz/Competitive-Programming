#include <bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define ALL(v) v.begin(), vend()
#ifdef DEBUG
#define fast
#else
#define fast ios::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define cerr if(0);else cerr
#endif
#define _ <<' '<<
using ll = long long;
using pii = pair<int, int>;
 
signed main() {
    fast;
 
    int n;
    cin >> n;
    array<bool,365> v{};
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x-1] = true;
    }
    int ans = 0;
    int s = 0, c = 0;
    for(int i = 0; i < 365; i++) {
        if (s+c >= 20) {
            // cerr _ i _ s _ endl;
            ans++;
            s = c = 0;
        }
        s += c;
        c += v[i];
    }
    if (c) ans++;
    cout << ans << endl;
 
}