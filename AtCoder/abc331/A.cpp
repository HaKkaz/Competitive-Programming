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
    int M, D; // have M months and D days each year
    int y, m, d; // current date 
    cin >> M >> D >> y >> m >> d;

    // next date
    d++;
    if (d > D) {
        d = 1;
        m++;
    }
    if (m > M) {
        m = 1;
        y++;
    }
    cout << y _ m _ d << endl;
}
