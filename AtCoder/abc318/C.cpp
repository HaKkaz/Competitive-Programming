#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d, p;
    cin >> n >> d >> p;
    vector<int> f(n);
    for (int &x : f) cin >> x;
    sort(begin(f), end(f), greater<int>());

    int cnt = 0;
    long long sum = 0, ans = 0;
    for(int i = 0; i < n; ++i) {
        sum += f[i];
        cnt++;
        if (cnt == d) {
            ans += min(1LL*p, sum);
            sum = 0;
            cnt = 0;
        }
    }
    if (cnt) {
        ans += min(1LL*p, sum);
    }
    cout << ans << '\n';
}
