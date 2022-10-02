#include"bits/stdc++.h"
#define IOS ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 105;
int dp[205][105][105]; // i steps , a at (j , i-j) , b at (k , i-k)
int a[maxn][maxn];
inline void umax(int &a , int b){
	if(b > a) a = b;
}
signed main(){
	IOS;
	int n , m; cin >> n >> m;
	int sum = 0;
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=m ; ++j)
			cin >> a[i][j] , sum += a[i][j]==-1;

	for(int step=0 ; step<=n+m-2 ; ++step)
		for(int i=0 ; i<=n ; ++i)
			for(int j=0 ; j<=n ; ++j)
				dp[step][i][j] = -1e9;
	//
	dp[0][1][1] = a[1][1]==1;
	if(a[1][1] == -1) return cout << 0 << '\n' , 0;
 	for(int step=1 ; step<=n+m-2 ; ++step){
		for(int i=1 ; i<=n ; ++i){
			for(int j=1 ; j<=n ; ++j){
				int x1 , y1 , x2 , y2;
				x1 = i , y1 = step-i+2 , x2 = j , y2 = step-j+2;
				if(y1 > m || y2 > m || y1 <= 0 || y2 <= 0) continue;
				if(a[x1][y1] == -1 || a[x2][y2] == -1) continue;
				int val = (a[x1][y1]==1) + (a[x2][y2]==1) - (a[x1][y1] == 1 && i==j);
				int &now = dp[step][i][j];
				umax(now , dp[step-1][i][j]);
				umax(now , dp[step-1][i-1][j]);
				umax(now , dp[step-1][i][j-1]);
				umax(now , dp[step-1][i-1][j-1]);
				now += val;
			}
		}
	}
	cout << max(0,dp[n+m-2][n][n]) << '\n';
}