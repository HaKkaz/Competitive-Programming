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

signed main() { fast;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> dish(n);
    vector< pii > side(m);
    vector< pii > rej(k);
    for (auto &x : dish) cin >> x;
    for (int i = 0; i < m; ++i) cin >> side[i].ft, side[i].sd = i;
    for (auto &[x, y] : rej) cin >> x >> y, --x, --y;

    sort(ALL(side));
    sort(ALL(rej));

    // {sum, d_idx, s_idx}
    priority_queue< tuple<int,int,int> > pq;
    for (int i = 0; i < n; ++i) {
        pq.emplace(dish[i] + side[m-1].ft, i, m-1);
    }

    while(pq.size()) {
        auto [sum, d_idx, s_idx] = pq.top(); pq.pop();
        int ss_idx = side[s_idx].sd; // original side index
        bool check = binary_search(ALL(rej), pii(d_idx, ss_idx));
        if (!check) {
            cout << sum << '\n';
            return 0;
        } else if (s_idx-1 >= 0){
            pq.emplace(dish[d_idx] + side[s_idx-1].ft, d_idx, s_idx-1);
        }
    }
}
