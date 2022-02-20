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

bitset<30> str[20005];

signed main(){
    fast;
    int n,k;
    cin >> n >> k;
    int ans = 1000;
    for(int i=0 ; i<n ; ++i){
        string s; cin >> s;
        str[i] = bitset<30>(s);
        for(int j=0 ; j<i ; ++j){
            ans = min(ans , (int)(str[i] ^ str[j]).count() );
        }
    }
    cout << ans << '\n';
}

