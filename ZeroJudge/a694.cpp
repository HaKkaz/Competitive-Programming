#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define endl cout<<'\n';
using namespace std;
const int maxn = 505;
int num[maxn][maxn] , p[maxn][maxn] , n , m , a , b , c , d;
inline void bulid(){
	for(int i=1 ; i<=n ; ++i)
			for(int j=1 ; j<=n ; ++j)
				cin >> num[i][j];
	for(int i=1 ; i<=n ; ++i)
		for(int j=1 ; j<=n ; ++j)
			p[i][j] = 0 , p[i][j] += p[i][j-1] + p[i-1][j] - p[i-1][j-1] + num[i][j];
}
inline void solve(){
	while(cin >> n >> m){
		bulid();
		while(m--){
			cin >> a >> b >> c >> d;
			cout << p[c][d] + p[a-1][b-1] - p[a-1][d] - p[c][b-1] << '\n';
		}
	}
}
signed main(){IOS;solve();}