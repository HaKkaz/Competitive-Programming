#include"bits/stdc++.h"
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define LINE cout<<"--------------------------\n";
#define IOS ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 105;
int kkkkk[maxn][maxn];
int dx[]={1 , 1 , 1 , 0 , -1 , -1 , -1 , 0},dy[]={1 , 0 , -1 , -1 , -1 , 0 , 1 , 1};
signed main(){
	IOS;
	int n , q;
	while(cin >> n >> q){
		memset(kkkkk , 0 , sizeof(kkkkk));
		while(q--){
			int x , y; cin >> x >> y;
			++x , ++y;
			swap(x , y);
			kkkkk[x][y] = 1;
		}
		for(int i=1 ; i<=n ; ++i){
			for(int j=1 ; j<=n ; ++j){
				if(kkkkk[i][j]){
					cout << 'x';
					continue;
				}
				int res = 0;
				for(int t=0 ; t<8 ; ++t){
					res += kkkkk[i+dx[t]][j+dy[t]];
				}
				cout << res;
			}
			cout << '\n';
		}
	}
	
}