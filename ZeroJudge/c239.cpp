#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define rep(a , b) for(int ii=a ; ii<b ; ++ii)
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int INF = 1e9;
int G[16][16] , dis;
int dp[17][1<<17];
int dpmn[17][1<<17];
int MN , mx;
void init(int n){
	MN = INF , mx = 0;
	for(int i=0 ; i<17 ; ++i)
		for(int j=0 ; j<(1<<n) ; ++j)
			dp[i][j] = 0;	

	for(int i=0 ; i<n ; ++i)
		for(int j=0 ; j<(1<<n) ; ++j)
			dpmn[i][j] = INF;

}
int main(){
__IO
	int n;
	while(cin >> n){
		init(n);
		for(int i=0 ; i<n-1 ; ++i){
			for(int j=i+1 ; j<=n-1 ; ++j){
				cin >> dis;
				G[i][j] = dis;
				G[j][i] = dis;
			}
		}
		for(int j=0 ; j<(1<<(n-1)) ; ++j){
			for(int i=0 ; i<n-1 ; ++i){
				if(j == 1<<i) dp[i][j] = G[n-1][i];
				else if(j&(1<<i)){
					for(int x=j ; x ; x -= (x&-x)){
						if((x&-x)==1<<i) continue;
						dp[i][j] = max(dp[i][j] , dp[__lg(x&-x)][j^(1<<i)]+G[__lg(x&-x)][i]);
					}
				}
			}
		}
		for(int i=0 ; i<n-1 ; ++i)
			mx = max(mx , dp[i][(1<<(n-1))-1]+G[i][n-1]);
		
		for(int j=0 ; j<(1<<(n-1)) ; ++j){
			for(int i=0 ; i<n-1 ; ++i){
				if(j == 1<<i) dpmn[i][j] = G[n-1][i];
				else if(j & (1<<i)){
					for(int x=j ; x ; x -= (x&-x)){
						if((x&-x) == 1<<i) continue;
						dpmn[i][j] = min(dpmn[i][j] , dpmn[__lg(x&-x)][j^(1<<i)] + G[__lg(x&-x)][i]);
					}
				}
			}
		}
		for(int i=0 ; i<n-1 ; ++i)
			MN = min(MN ,  dpmn[i][(1<<(n-1))-1] + G[i][n-1]);
		
		int GCD = __gcd(mx , MN);
		if(MN / GCD == 1) cout << mx/GCD <<'\n';
		else cout << mx/GCD << '/' << MN/GCD << '\n';
	}
}