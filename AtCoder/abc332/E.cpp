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

const int N = 15;
long double dp[1 << N][16];

signed main() {
    fast;
    int n, d;
    cin >> n >> d;
    vector<int> w(n);
    for (int &x : w) cin >> x;

    long double avg = accumulate(w.begin(), w.end(), 0LL) / (long double)d;
    
    for (int i = 0; i < (1 << n); ++i) {
        long double sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i >> j & 1) {
                sum += w[j];
            }
        }
        ld q = sum - avg;
        dp[i][1] = pow(q, 2);

        for (int j = 2; j <= d; ++j) {
            dp[i][j] = dp[i][j-1] + dp[0][1];

            // enumerate subset
            int s = i;
            while (s) {
                dp[i][j] = min(dp[i][j], dp[i^s][j-1] + dp[s][1]);
                s = (s-1) & i;
            }
        }
    }

    cout << fixed << setprecision(10) << dp[(1 << n)-1][d] / (long double)d << endl;
}