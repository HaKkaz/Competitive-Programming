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

constexpr ll MOD = 1e9+7;

#define int ll

ll inverse(ll x) {
    ll r = 1, b = MOD-2;
    while (b) {
        if (b&1) r = r*x%MOD;
        x = x*x%MOD;
        b >>= 1;
    }
    return r;
}

signed main() {
    fast;

    int n, k;
    cin >> n >> k;
    vector<int> p(n,-1);
    for(int i = 1; i < n; i++)
        cin >> p[i];

    vector<int> inv(k+1);
    for(int i = 2; i <= k; i++)
        inv[i] = inverse(i);

    auto calc = [&](int k) {
        vector<ll> dp(n,1);
        for(int i = n-1; i > 0; i--) {
            dp[p[i]] *= dp[i];
            dp[p[i]] %= MOD;
            dp[p[i]] *= k-1;
            dp[p[i]] %= MOD;
        }
        return dp[0] * k % MOD;
    };

    vector<int> dp(k+1);
    for(int i = 2; i <= k; i++)
        dp[i] = calc(i);


    // C(n,m) = n!/(m!*(n-m)!)
    // m! -> m+1!
    // (n-m)! -> (n-m-1)!
    // (n-m)/(m+1)
    // 5,1: 5!/1*4*3*2
    // 5,2: 5!/1*2*3*2

    for(int i = 3; i <= k; i++) {
        ll r = i*(i-1)/2;
        for(int j = 2; j < i; j++) {
            // cerr _ i _ dp[i] _ j _ dp[j] _ r _ endl;
            dp[i] -= dp[j]*r%MOD;
            if (dp[i] < 0) dp[i] += MOD;
            r = r * (i-j) % MOD * inv[j+1] % MOD;
        }
    }

    // for(int i = 2; i <= k; i++)
        // cerr << dp[i] << " \n"[i==k];
    cout << dp[k] << endl;

}
