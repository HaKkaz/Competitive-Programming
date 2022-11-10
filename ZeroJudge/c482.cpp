#include<iostream>
#include<time.h>

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define endl cout<<'\n';
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 2005;
int tab[maxn][maxn] , ans , n , x ,tot , cnt;
void solve(){
	srand(time(0));
	while(cin >> n && n){
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<n ; ++j){
				cin >> tab[i][j];
			}
		}
		int q; cin >> q;
		while(q--){
			int r1 , r2 , c1 , c2 , T = 5;
			cin >> r1 >> r2 >> c1 >> c2;
			ans = -1;
			while(T--){
				int rdx = rand()%(r2-r1)+r1 , rdy = rand()%(c2-c1)+c1;
				x = tab[rdx][rdy];
				tot = cnt = 0;
				for(int i=r1 ; i<=r2 ; ++i){
					for(int j=c1 ; j<=c2 ; ++j){
						++tot;
						if(tab[i][j] == x) ++cnt;
					}
				}
				if(cnt > tot/2){
					ans = x;
					break;
				}
			}
			cout << ans << '\n';
		}
	}
}
signed main(){
	loli
	solve();
}