#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(1);else cerr
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

signed main(){
    fast;
    // a(2,1) + b(1,2) = x,y
    // 2a + b = x
    // a + 2b = y
    // a - b = (x-y)
    // 3a + 3b = x + y
    // a + b = (x+y
    // )/3
    //
    int t; cin >> t; while(t--) {
        int a,b; cin >> a >> b;
        cout << ( (a + b) % 3 == 0 and max(a,b) <= min(a,b)*2 ? "YES\n" : "NO\n");
    }
}

