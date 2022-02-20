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
    string s; cin >> s;
    sort(ALL(s));
    vector<string> ans;
    do{
        ans.emplace_back(s);
    }while(next_permutation(ALL(s)));
    cout << ans.size() << '\n';
    for(auto &it : ans) cout << it << '\n';
}

