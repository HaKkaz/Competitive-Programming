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
    string s;
    cin >> s;
    char now = '.';
    int cnt = 0 , ans = 0 ;
    for(auto &ch : s){
        if(ch == now) ++cnt;
        else cnt = 1 , now = ch;
        ans = max(ans , cnt);
    }
    cout << ans << '\n';
}

