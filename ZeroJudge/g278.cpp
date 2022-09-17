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

int cnt[100005];

signed main(){
    fast;
    int n,k; cin >> n >> k;

    vector<int> arr(n+1);
    vector< vector<int> > dp(2 , vector<int>(n+1,0));

    for(int i=1 ; i<=n ; ++i){
        cin >> arr[i];
    }

    int ans = 0 ;

    for(int i=1 ; i<=k ; ++i){
        int two = 0 , pos = 1;
        for(int j=1 ; j<=n ; ++j){
            cnt[arr[j]]++;
            if(cnt[arr[j]] == 2) ++two;
            while(two > 0){
                cnt[arr[pos]]--;
                if(cnt[arr[pos]] == 1) --two;
                ++pos;
            }
            dp[1][j] = max({dp[0][pos-1] + (j-pos+1) , dp[0][j] , dp[1][j-1]});

            ans = max(ans , dp[1][j]);
        }
        while(pos <= n) cnt[arr[pos]]--, pos++;
        swap(dp[0] , dp[1]);
    }

    cout << ans << '\n';

}