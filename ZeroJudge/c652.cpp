#include<iostream>
#include<math.h>
#pragma GCC optimize ("Ofast")
#define pb push_back
#define mp make_pair
#define Sz(x) (int)(x).size()
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
#define int long long 
const int maxn = 3e5+5;
int seg[4*maxn];
void build(int l , int r , int rt){
	if(l == r) return cin >> seg[rt] , void();
	int m = (l+r)>>1;
	build(l , m , rt<<1);
	build(m+1 , r , rt<<1|1);
	seg[rt] = seg[rt<<1] + seg[rt<<1|1];
}

void modify(int L , int R , int l , int r , int rt){
	if(seg[rt] == (r-l+1)) return;
	if(l == r) return seg[rt] = sqrt(seg[rt]) , void();
	int m = (l+r)>>1;
	if(L <= m) modify(L , R , l , m , rt<<1);
	if(R > m ) modify(L , R , m+1 , r , rt<<1|1);
	seg[rt] = seg[rt<<1] + seg[rt<<1|1];
}

int query(int L , int R , int l , int r , int rt){
	if(l == r) return seg[rt];
	int m = (l+r)>>1;
	if(L <= l && R >= r) return seg[rt];
	if(R <= m) return query(L , R , l , m , rt<<1);
	if(L > m)  return query(L , R , m+1 , r , rt<<1|1);
	return query(L , R , l , m , rt<<1) + query(L , R , m+1 , r , rt<<1|1);                                               
}

signed main(){
__IO
	int n , q;
	cin >> n >> q;
	build(1 , n , 1);
	while(q--){
		int a , x , y;
		cin >> a >> x >> y;
		if(a == 0) cout << query(x , y , 1 , n , 1) << '\n';
		else modify(x , y , 1 , n , 1);
	}
}
/* 
10 3
1 2 3 4 5 6 7 8 9 10
0 1 10
1 1 10
0 1 10
*/