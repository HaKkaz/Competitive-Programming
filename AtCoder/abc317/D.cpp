#pragma GCC optimize("Ofast,unroll-loops,fast-math")
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
    int n; cin >> n;
    vector<int> X(n), Y(n), Z(n);
    int TAR = 0;
    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i] >> Z[i];
        TAR += Z[i];
    }
    int SUM = TAR;
    TAR = (TAR+1)/2;

    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        int tot = X[i] + Y[i];
        if (X[i] < Y[i]) cost[i] = (tot+1)/2 - X[i];
        else cost[i] = 0;
    }

    const ll INF = 1e14; 
    vector<ll> dp(SUM+1, INF);
    dp[0] = 0;
    ll ans = INF;
    for (int j = 0; j < n; ++j) {
        for (int i = SUM; i >= 0; --i) {
            if (i + Z[j] > SUM) continue;
            dp[i + Z[j]] = min((ll)dp[i + Z[j]], dp[i] + cost[j]);
            if (i + Z[j] >= TAR) {
                ans = min(ans, dp[i+Z[j]]);
            }
        }
    }
    cout << ans << '\n';
}

