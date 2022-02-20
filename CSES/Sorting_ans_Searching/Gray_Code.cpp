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
    int n; cin >> n;
    vector< string > v;
    v.push_back("0");
    v.push_back("1");

    for(int i=2 ; i<=n ; ++i){
        auto a = v;
        auto b = v;
        reverse(ALL(b));
        v.clear();

        for(auto &str : a) v.emplace_back(str + "0");
        for(auto &str : b) v.emplace_back(str + "1");

    }

    for(auto &str : v) cout << str << '\n';
}

