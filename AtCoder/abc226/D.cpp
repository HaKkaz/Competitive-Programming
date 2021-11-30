#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long ;
using ld = long double ;
using pii = pair<int,int> ;
set< pii > cnt;
signed main(){
	fast;

    int n; cin >> n ;
    vector<int> x(n+1) , y(n+1);
    for(int i=1 ; i<=n ; ++i){
        cin >> x[i] >> y[i];   
        for(int j=1 ; j<i ; ++j){
            int a = x[i] - x[j];
            int b = y[i] - y[j];
            int gg = __gcd(a,b);
            if(gg == 0){
                if(a == 0) cnt.insert({0 , 1}) , cnt.insert({0 , -1});
                if(b == 0) cnt.insert({1 , 0}) , cnt.insert({-1 , 0});
            }
            a /= gg;
            b /= gg;
            cnt.insert({a,b});
            cnt.insert({-a , -b});
        }
    }
    cout << cnt.size() << '\n';
    ;
}

