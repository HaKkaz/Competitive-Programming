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

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll x = !!(a+b+c), y = !!(b+c+d);
    while (x*(x-1)/2 < a) x++;
    while (y*(y-1)/2 < d) y++;

    bool can = true;
    can &= x*(x-1)/2 == a;
    can &= y*(y-1)/2 == d;
    can &= (x+y)*(x+y-1)/2 == a+b+c+d;
    can &= x*y == b+c;

    cerr _ x _ y _ endl;

    string ans;
    if (a+b+c+d == 0)
        ans = "0";
    else if (!can)
        ans = "impossible";
    else if (x == 0)
        ans = string(y,'1');
    else if (y == 0)
        ans = string(x,'0');
    else {
        int L = c / x;
        int R = b / x;
        int z = L+R+1 == y;
        assert(L+R+z == y);
        int l = b % x;
        int r = c % x;
        if (l == 0 and r == 0)
            l = x;
        assert(l+r == x);
        // cerr _ L _ R _ l _ r _ endl;
        ans = string(L,'1') + string(l,'0') + string(z,'1') + string(r,'0') + string(R,'1');
    }

    cout << ans << endl;

}
