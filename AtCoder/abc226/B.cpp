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

signed main(){
	fast;

    int n; cin >> n;
    vector< vector<int> > vs(n);
    for(auto &v : vs){
        int k; cin >> k ;
        v.resize(k);
        for(auto &x : v) cin >> x;
    }
    sort(ALL(vs));
    cout << unique(ALL(vs)) - vs.begin() << '\n';
    ;
}

