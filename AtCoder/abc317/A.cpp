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
    int n, h, x;
    cin >> n >> h >> x;
    for (int i = 0; i < n; ++i) {
        int y; cin >> y;
        if (h + y >= x) {
            cout << i + 1 << '\n';
            break;
        }
    }
}
