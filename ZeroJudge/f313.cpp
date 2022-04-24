#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int dp[2][55][55] ;
signed main(){
	IOS;
	int R , C , k , m;
	cin >> R >> C >> k >> m ;
	for(int i=0 ; i<55 ; ++i)for(int j=0 ; j<55 ; ++j)dp[0][i][j] = -1;
	for(int i=1 ; i<=R ; ++i){
		for(int j=1 ; j<=C ; ++j){
			cin >> dp[0][i][j];
		}
	}
	while(m--){
		int cnt[55][55];
		for(int i=1 ; i<=R ; ++i)for(int j=1 ; j<=C ; ++j)cnt[i][j]=0,dp[1][i][j]=0;
		for(int i=1 ; i<=R ; ++i){
			for(int j=1 ; j<=C ; ++j){
				if(dp[0][i][j] == -1){
					dp[1][i][j] = -1;
					continue;
				}
				for(int c=0 ; c<4 ; ++c){
					int x = i+dx[c] , y = j+dy[c];
					if(dp[0][x][y] == -1) continue;
					dp[1][i][j] += dp[0][x][y]/k;
					cnt[x][y]++;
				}
			}
		}
		for(int i=1 ; i<=R ; ++i){
			for(int j=1 ; j<=C ; ++j){
				if(dp[0][i][j]==-1) continue;
				dp[0][i][j] -= cnt[i][j] * (dp[0][i][j]/k);
				dp[1][i][j] += dp[0][i][j];
			}
		}
		swap(dp[0] , dp[1]);
	}
	int mx = 0 , mn = 1e9;
	for(int i=1 ; i<=R ; ++i)
		for(int j=1 ; j<=C ; ++j){
			if(dp[0][i][j] == -1) continue;
			mx = max(mx , dp[0][i][j]);
			mn = min(mn , dp[0][i][j]);
		}
	cout << mn << '\n' << mx << '\n';
}