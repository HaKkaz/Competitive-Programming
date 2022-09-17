#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;


signed main(){
	fast;
	int t=1;
	cin >> t;
	while(t--){
		int n , m , q;
		cin >> n >> m >> q;
		//delta
		int dx[]={1,-1, 1,-1};
		int dy[]={1, 1,-1,-1};
		int nn[]={1, n, 1, n};
		int mm[]={1, 1, m, m};

		//input
		vector< vector<char> > arr(n+2 , vector<char>(n+2 , 0));
		vector< vector< vector<int> > > dp(4 , vector< vector<int> > (n+2 , vector<int>(m+2 , 0)));
		for(int i=1 ; i<=n ; ++i){
			for(int j=1 ; j<=m ; ++j){
				cin >> arr[i][j];
			}
		}
		//build dp table of four directions
		for(int i=0 ; i<4 ; ++i){
			for(int x=nn[i] ; x>=1 && x<=n ; x+=dx[i]){
				for(int y=mm[i] ; y>=1 && y<=m ; y += dy[i]){
					//same
					int px = x - dx[i];
					int py = y - dy[i];
					if(arr[x][y] == arr[px][y] && arr[x][y] == arr[x][py] ){
						int h = min(dp[i][px][y] , dp[i][x][py]);
						int hx = x-h*dx[i];
						int hy = y-h*dy[i];
						if(arr[x][y] == arr[hx][y] && arr[x][y] == arr[x][hy]){
							dp[i][x][y] = h + 1;
						}
						else{
							dp[i][x][y] = h;
						}
					}
					else{
						dp[i][x][y] = 1;
					}
				}
			}
		}
		cout << n << ' ' << m << ' ' << q << '\n';
		while(q--){
			int qx,qy; cin >> qx >> qy;
			++qx,++qy;
			int mnh = 10000;
			for(int i=0 ; i<4 ; ++i) mnh = min(mnh , dp[i][qx][qy]);
			cout << (mnh - 1)*2 + 1 << '\n';	
		}
	}
}
