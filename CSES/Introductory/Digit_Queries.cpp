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
    
    auto solve = [&](){
        ll n; cin >> n;
        for(ll i=9,j=1 ; ; i*=10,j++){
            if(n <= i * j){
                ll bas = 1;
                for(ll z=1 ; z<j ; ++z){
                    bas *= 10;
                }
                bas += n/j-1;
                if(n%j==0) cout << bas%10 << '\n';
                else{
                    ++bas;
                    string s = to_string(bas);
                    cout << s[n%j-1] << '\n';
                }
                return;
            }
            else{
                n -= i * j;   
            }
        }
    };

    int t; cin >> t;
    while(t--){
        solve();
    }
}   

