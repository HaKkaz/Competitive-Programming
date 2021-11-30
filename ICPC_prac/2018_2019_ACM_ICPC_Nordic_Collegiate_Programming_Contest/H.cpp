#include <bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define ALL(v) v.begin(), v.end()
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
    // fast;
 
    int l, m;
    scanf("%d %d", &l, &m);
    vector<tuple<string,int,int,int,int>> v(m);
    for(auto &[n,p,c,t,r]: v) {
        char s[70];
        getchar();
        scanf("%[^,]s", s);
        scanf(",%d,%d,%d,%d", &p, &c, &t, &r);
        n = string(s);
    }
 
    int mn = 1e7;
    vector<string> ans{};
    for(auto &[n,p,c,t,r]: v) {
        int z = t+r;
        /*
        int g = __gcd(z, 10080);
        int k = z * 10080 * g;
        bool can = 1ll*c*t*(k/z) >= 1ll*l*(k/10080);
        */
        bool can = 1ll*c*t*10080 >= 1ll*l*z;
        if (can) {
            if (p < mn) mn = p, ans.clear();
            if (p == mn) ans.emplace_back(n);
        }
    }
 
    if (ans.empty()) ans.emplace_back("no such mower");
    for(auto s: ans) cout << s << endl;
 
}