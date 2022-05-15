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

const int maxn = 2e5+50;
set<int> Ro[maxn] , Co[maxn];

int bit[2][maxn];
void upd(int i , int k , int id){
	for( ; i < maxn ; i += (i & -i))
		bit[id][i] += k;
}
int qry(int i , int id){
	int ret = 0 ;
	for( ; i ; i -= (i & -i))
		ret += bit[id][i];
	return ret;
}

signed main(){
	fast;
	int t=1;
	// cin >> t;
	while(t--){
		int n , q;  cin >> n >> q;
		while(q--){
			int opt ; cin >> opt;
			int x,y; cin >> x >> y;
			if(opt == 1){
				Ro[x].emplace(y);
				Co[y].emplace(x);
				if(Ro[x].size() == 1){
					upd(x , 1 , 0);
				}
				if(Co[y].size() == 1){
					upd(y , 1 , 1);
				}
			}
			if(opt == 2){
				Ro[x].erase(y);
				Co[y].erase(x);
				if(Ro[x].size() == 0){
					upd(x , -1 , 0);
				}
				if(Co[y].size() == 0){
					upd(y , -1 , 1);
				}

			}
			if(opt == 3){
				int xx,yy;
				cin >> xx >> yy;
				int Lx = qry(x-1 , 0);
				int Rx = qry(xx , 0);
				int Ly = qry(y-1 , 1);
				int Ry = qry(yy , 1);
				// cout << Lx << ' ' << Rx << ' ' << xx-x+1 << '\n';
				// cout << Ly << ' ' << Ry << ' ' << yy-y+1 << '\n';
				bool ok = ((Rx-Lx)==xx-x+1) | ((Ry-Ly)==yy-y+1);
				cout << (ok ? "Yes" : "No") << '\n';
			}
		}
	}
}