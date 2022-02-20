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
    int n ; cin >> n ;
    vector<int> a;
    for(int i=0 ; i<n ; ++i){
        int l , r; cin >> l >> r;
        a.push_back(l);
        a.push_back(-r);
    }
    sort(ALL(a) , [](const int &x , const int &y){
            return abs(x) < abs(y);
    });
    
    int ans = 0 , cnt = 0;
    n<<=1;
    for(int i=0 ; i<n ; ++i){
        int t = a[i];
        if(t < 0) --cnt;
        else ++cnt;

        if(i + 1 >= n or abs(a[i+1]) != abs(a[i])){
            ans = max(ans , cnt);
        }
    }
    cout << ans << '\n';
}

