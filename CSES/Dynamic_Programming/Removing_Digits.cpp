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
int dp[1000005];
int solve(int now){
    if(dp[now]) return dp[now];
    if(now == 0) return 0;

    int mn = 1000000;
    for(int i=now ; i ; i/=10){
        int tp = i%10;
        if(tp)
            mn = min(mn , solve(now - tp) + 1);
    }
    
    return dp[now] = mn;
}
signed main(){
    fast;
    int n; cin >> n;
    cout << solve(n);
}

