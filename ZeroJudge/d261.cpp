#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define ft first
#define sd second
#define ALL(v) v.begin(),v.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define cerr if(0);else cerr
#define _ << ' ' << 

int main(){
	fast;

    int n ;
    while(cin >> n){
        if(n == -1) return 0;
        vector< array<ll,2> > dp(n+1);
        dp[0][0] = 1;
        dp[0][1] = 0;
        for(int i=1 ; i<=n ; ++i){
            dp[i][0] = 1 + dp[i-1][1];
            dp[i][1] = dp[i-1][0] + dp[i-1][1];
        }
        cout << dp[n][1] << ' ' << dp[n][0] + dp[n][1] << '\n';
    }
}

