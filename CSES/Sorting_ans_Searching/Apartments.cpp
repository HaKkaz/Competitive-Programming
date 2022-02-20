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
    int n , m , k;
    cin >> n >> m >> k;

    vector<int> wt(n) , ht(m);
    for(int &x : wt) cin >> x;
    for(int &x : ht) cin >> x;
    sort(ALL(ht));
    sort(ALL(wt));

    int top = 0 , ans = 0;
    for(int i=0 ; i<m ; ++i){
        while(top < n and  wt[top]+k < ht[i]) ++top;
        if(top < n and wt[top]-k <= ht[i]) ++ans , ++top;
    }
    cout << ans << '\n';
}

