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
const int mod = 1e9+7;

signed main(){
    fast;
    int n; cin >> n;
    vector<int> dp(n+1 , 0);
    dp[0]=1;
    for(int i=1 ; i<=n ; ++i){
        for(int j=i-1 ; j>=0 and j>=i-6 ; j--){
            dp[i] += dp[j];
            if(dp[i] >= mod) dp[i] -= mod;
        }
    }
    cout << dp[n] << '\n';
}

