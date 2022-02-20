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

    auto solve = [&](){
        int n , k ; cin >> n >> k ;
        vector< int > psum(n+1,0) , dp(n+1,0);
        for(int i=1 ; i<=n ; ++i) cin >> psum[i];
        partial_sum(psum.begin()+1 , psum.end() , psum.begin()+1);

        for(int &x : psum) cout << x << ' ' ;
        cout << endl;
        
        int ans = 0 ;
        multiset< pair<int , int> > mst;
        mst.emplace(0,0);
        for(int i=1 ; i<=n ; ++i){
            mst.emplace(dp[i-1] - psum[i] , i);
            if(i-k-1 >= 0){
                mst.erase( pii(dp[ max(i-k-2,0) ]-psum[i-k-1] , i-k-1) );    
            }
            dp[i] = psum[i] + mst.rbegin()->ft;
            ans = max(ans , dp[i]);
            // cout << i << ' ' << mst.rbegin()->ft _ mst.rbegin()->sd _ endl;
        }
        // for(int i=1 ; i<=n ; ++i) cout << dp[i-1]-psum[i] << ' ' ;
        // cout << endl;
        cout << ans << '\n';

    };

    solve();

}

