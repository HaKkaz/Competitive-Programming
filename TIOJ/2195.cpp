#include <bits/stdc++.h>
#pragma GCC optimize("Ofast" , "fast-math" , "unroll-loops")
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
using ll = long long ;
using ld = long double ;
using pii = pair<int,int> ;
vector<int> a,b,from,dp(1,-1);
vector<int> best;
map<int,int> idx;

signed main(){
	fast;
    int n; cin >> n ;
    a.resize(n+1);
    b.resize(n+1);
    from.resize(n+1);
    best.resize(n+1 , 0);
    a[0] = -1 , b[0] = 0;

    for(int i=n ; i>=1 ; --i) cin >> a[i] , idx[ a[i] ] = i;
    for(int i=n ; i>=1 ; --i) cin >> b[i] , b[i] = idx[b[i]];

    for(int i=1 ; i<=n ; ++i){
        int x = b[i];
        auto it = lower_bound(ALL(dp) , x);
        int pos = it-dp.begin();
        from[x] = best[pos-1];

        if(it == dp.end()){
            best[pos] = x;
            dp.push_back(x);  
        }
        else{
            if(a[x] > a[ best[pos] ]) best[pos] = x;
            *it = x;
        }
    }
    cerr _ "meow" _ endl;

    for(int i=1 ; i<=n ; ++i) cerr _ a[ best[i] ] _ ' ' ;
    cerr _ endl;

    int now = best[dp.size()-1];
    cerr _ dp.size() _ endl;
    // cerr _ now _ endl;
    vector<int> ans;
    while(now){
        ans.push_back(a[now]);
        now = from[now];
    }
    for(int &c : ans) cout << c << ' ';
    ;
}

