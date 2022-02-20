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
    int n , m ; 
    cin >> n >> m;

    multiset<int> tickets;
    for(int i=0 ; i<n ; ++i){
        int x; cin >> x;
        tickets.insert(x);
    }

    for(int i=0 ; i<m ; ++i){
        int wanna; cin >> wanna;
        auto it = tickets.upper_bound(wanna);
        if(it != tickets.begin()){
            it = prev(it) , cout << *it << '\n';
            tickets.erase(it);
        }
        else cout << -1 << '\n';
    }

}

