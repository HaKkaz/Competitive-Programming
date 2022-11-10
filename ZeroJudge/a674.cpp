#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int INF = 1e9;
int dis[101][101];
int dp[101][101];
int C , S , Q , a , b , w;
void floyed(){
	for(int k=1 ; k<=C ; ++k){
		for(int i=1 ; i<=C ; ++i){
			for(int j=1 ; j<=C ; ++j){
				if(i == j) continue;
				dp[i][j] = min(dp[i][j] , max(dp[i][k] , dp[k][j]));
			}
		}
	}
}
int main(){
__IO
	int cnt = 0;
	while(cin >> C >> S >> Q && C+S+Q){
		++cnt;
		for(int i=1 ; i<=C ; ++i)
			for(int j=1 ; j<=C ; ++j)
				dp[i][j] = INF;
		for(int i=0 ; i<S ; ++i){
			cin >> a >> b >> w;
			dp[a][b] = w;
			dp[b][a] = w;
		}
		floyed();
		cout << "Case #"<<cnt << '\n';
		while(Q--){
			cin >> a >> b;
			if(dp[a][b] == INF) cout << "no path\n";
			else cout << dp[a][b] << '\n';
		}
		cout << '\n';
	}	
}