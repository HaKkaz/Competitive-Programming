#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
#define rep(a , b , c) for(int c = a ; c < b ; ++c)
using namespace std;
int S[51] , dp[51][51];
int main(){
//__IO
	int L;
	while(cin >> L && L){
		int n ; cin >> n;
		for(int i=1 ; i<=n ; ++i) cin >> S[i];
		S[++n] = L ;
		for(int i=2 ; i<=n ; ++i){
			for(int l = 0 , r = l+i ; r <= n ; ++l , ++r){
				int now , mn = 1e9+7;
				for(int m = l+1 ; m<r ; ++m){
					now = dp[l][m] + dp[m][r] + S[r] - S[l];
					if(mn > now) mn = now;
				}
				dp[l][r] = mn;
			}
		}
		cout << "The minimum cutting is "<<dp[0][n]<<".\n";
	}
}