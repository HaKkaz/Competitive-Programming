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
#define int long long
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

signed main(){
    fast;
    int n , t;
    cin >> n >> t;
    
    vector<int> a(n);
    for(int &x : a) cin >> x;

    int l = 1 , r = 2000000000000000000LL/n;
    while(l < r){
        int mid = (l+r)/2;
        
        int tot = 0 ;
        for(auto &x : a) tot += mid/x;

        if(tot >= t) r = mid;
        else l = mid+1;
    }
    cout << l << '\n';
}

