#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
string a[200005];
unordered_map<string, int> mp;

signed main(){
    IOS;
    int m, n; cin >> m >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(mp[a[i]] == 1) --cnt;
        mp[a[i]]++;
        if(mp[a[i]] == 1) ++cnt;
        if(i - m >= 0) {
            if(mp[a[i - m]] == 1) --cnt;
            mp[a[i - m]]--;
            if(mp[a[i - m]] == 1) ++cnt;
        }
        ans += (cnt == m);
    }
    cout << ans;
}