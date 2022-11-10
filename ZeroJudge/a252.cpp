#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 105;
int dp[maxn][maxn][maxn];

inline void latina(){
	string a , b , c , s1 , s2 , s3;
	while(cin >> s1 >> s2 >> s3){
		a="$" , c="@" , b="#";
		a+=s1 , b+=s2 , c+=s3;
		int x = sz(a) , y = sz(b) , z = sz(c);
		for(int i=0 ; i<maxn ; ++i)
			for(int j=0 ; j<maxn ; ++j)
				for(int k=0 ; k<maxn ; ++k)
					dp[i][j][k] = 0;
		for(int i=1 ; i<x ; ++i){
			for(int j=1 ; j<y ; ++j){
				for(int k=1 ; k<z ; ++k){
					if(a[i] == b[j] and b[j] == c[k]){
						dp[i][j][k] = dp[i-1][j-1][k-1]+1;
			//			cout << a[i] << ' ' << b[j] << ' ' << c[k] << '\n';
					}
					else{
						dp[i][j][k] = max({dp[i-1][j][k] , dp[i][j-1][k] , dp[i][j][k-1]});
					}
				}
			}
		}
		cout << dp[x-1][y-1][z-1] << '\n';
	}
}
signed main(){loli;latina();}