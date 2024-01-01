#pragma GCC optimize("Ofast,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC ivdep // before loop
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
    int n, m;
    cin >> n >> m;
    
    vector<int> L(n);
    for (int &x : L) cin >> x;

    auto check = [&](ll width) {
        ll p = 0;
        int lines = 1;
        for (int &x : L) {
            if (x > width) return false;
            if (p + x <= width) p += x;
            else p = x, ++lines;
            ++p;
        }
        return lines <= m;
    };
    
    ll l = 0, r = 1e15;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}
