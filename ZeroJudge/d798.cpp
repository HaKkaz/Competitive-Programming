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
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 505;
int a[maxn][maxn] , seg[maxn*maxn<<2];
#define son1 (rt*4-2)
#define son2 (rt*4-1)
#define son3 (rt*4)
#define son4 (rt*4+1)
void build(int x1 , int x2 , int y1 , int y2 , int rt){
	//cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 <<  ' ' << rt << '\n';
	if(x1 == x2 && y1 == y2) return seg[rt] = a[x1][y1] , void();
	int midx = (x1+x2)>>1;
	int midy = (y1+y2)>>1;
	if(x1 == x2) build(x1 , x2 , y1 , midy , son1) , build(x1 , x2 , midy+1 , y2 , son3);
	else if(y1 == y2) build(x1 , midx , y1 , y2 , son1) , build(midx+1 , x2 , y1 , y2 , son2);
	else{
		build(x1 , midx , y1 , midy , son1);
		build(midx+1 , x2 , y1 , midy , son2);
		build(x1 , midx , midy+1 , y2 , son3);
		build(midx+1 , x2 , midy+1 , y2 , son4);
	}
	seg[rt] = max({seg[son1] , seg[son2] , seg[son3] , seg[son4]});
}
int qx1 , qx2 , qy1 , qy2;
int query(int x1 , int x2 , int y1 , int y2 , int rt){
	if(qx2 < x1 || qx1 > x2) return 0;
	if(qy2 < y1 || qy1 > y2) return 0;
	//cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << ' ' << rt << '\n';
	if(qx1 <= x1 && x2 <= qx2 && qy1 <= y1 && y2 <= qy2) return seg[rt];
	int midx = x1+x2>>1;
	int midy = y1+y2>>1;
	int A = query(x1 , midx , y1 , midy , son1);
	int B = query(midx+1 , x2 , y1 , midy , son2);
	int C = query(x1 , midx , midy+1 , y2 , son3);
	int D = query(midx+1 , x2 , midy+1 , y2 , son4);
	return max({A , B , C , D});
}
inline void latina(){loli;
	int n , m;
	cin >> n >> m;
	for(int i=1 ; i<=n ; ++i)for(int j=1 ; j<=m ; ++j)cin >> a[i][j];
	build(1 , n , 1 , m , 1);
	int Q; cin >> Q;
	while(Q--){
		cin >> qx1 >> qy1 >> qx2 >> qy2;
		cout << query(1 , n , 1 , m , 1) << '\n';
	}
}
signed main(){latina();}