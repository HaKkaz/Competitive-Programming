#include <bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define ALL(v) v.begin(), vend()
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
 
signed main() {
    fast;
 
    int n;
    cin >> n;
    bool can = true;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        can &= s == "mumble" or s == to_string(i);
    }
    cout << (can ? "makes sense" : "something is fishy") << endl;
 
}