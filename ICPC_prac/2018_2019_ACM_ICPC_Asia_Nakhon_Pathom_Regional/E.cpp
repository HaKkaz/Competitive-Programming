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

void chmax(int &a , int b){
    if(a < b) a = b;
}

void solve(){
    //after j times opt , stop at i and a_i is a_i+k , max value dp[i][j][k]
    int dp[105][3][3] , a[105];
    int n , ans = 0; cin >> n ;
    for(int i=1 ; i<=n ; ++i) cin >> a[i];
    sort(a+1,a+1+n);
    
    for(int i=0 ; i<=n ; ++i){
        for(int j=0 ; j<3 ; ++j){
            for(int k=0 ; k<3 ; ++k){
                dp[i][j][k] = -100000;
            }
        }
    }

    for(int i=1 ; i<=n ; ++i){
        dp[i][1][0] = 1;
        dp[i][0][1] = 1;
        dp[i][1][2] = 1;
    }

    for(int i=1 ; i<n ; ++i){//a[i]
        for(int j=0 ; j<3 ; ++j){
            for(int k=0 ; k<3 ; ++k){
                if(dp[i][j][k] < 0) continue;
                for(int k2 = 0 ; k2<3 ; ++k2){
                    int A = a[i+1] + k2 - 1;
                    int B = a[i] + k - 1;
                    if(abs(A - B) <= 2 && j+(k2!=1)<3) {
                        chmax(dp[i+1][j+(k2 != 1)][k2] , dp[i][j][k] + 1);
                    }
                }
            }
           
        }
    }

    for(int i=1 ; i<=n ; ++i)
        for(int j=0 ; j<3 ; ++j)
            for(int k=0 ; k<3 ; ++k)
                chmax(ans , dp[i][j][k]);

    cout << ans << '\n';
}
signed main(){
	fast;
    int t; cin >> t; 
    for(int T=1 ; T<=t ; ++T){
        cout << "Case" _ T << ": ";
        solve();
    }
    ;
}

