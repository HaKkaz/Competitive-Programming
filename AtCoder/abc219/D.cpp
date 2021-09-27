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
const int inf = 1e9;
int dp[305][305];
int main(){
	fast;
    int n ; cin >> n ; 
    int X , Y ; cin >> X >> Y;
    for(int i=0 ; i<=300 ; ++i)for(int j=0 ; j<=300 ; ++j)dp[i][j]=inf;
    int ans = inf;
    dp[0][0]=0;
    for(int i=0 ; i<n ; ++i){
        int a , b;
        cin >> a >> b;
        for(int x=300 ; x>=0 ; --x){
            for(int y=300 ; y>=0 ; --y){
                int aa = min(x + a , 300);
                int bb = min(y + b , 300);
                dp[aa][bb] = min(dp[x][y]+1 , dp[aa][bb]);
                if(aa >= X && bb >= Y && dp[aa][bb] < ans){
                    ans = dp[aa][bb];
                }
            }
        }
    }
    cout << (ans == inf ? -1 : ans) << '\n';
}

