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
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    map<int,int> L,R;
    ll ans = 0;
    ll tot = 0;
    for (int &x : a) {
        L[x]++;
    }

    for (int &x : a) {
        tot -= 1LL * L[x] * R[x];
        L[x]--;

        ans += tot;

        R[x]++;
        tot += 1LL * L[x] * R[x];
        
    }
    cout << ans << '\n';
}
