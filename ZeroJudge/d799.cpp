#include<iostream>
#include<math.h>
#include<vector>
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
#define int long long
using namespace std;
const int maxn = 5e5+10;
int seg[4*maxn] , lazy[4*maxn];
void build(int l , int r , int rt){
	if(l == r) return cin >> seg[rt] , void();
	int m = (l+r)>>1;
	build(l , m , rt<<1);
	build(m+1 , r , rt<<1|1);
	seg[rt] = seg[rt<<1] + seg[rt<<1|1];
}

void push(int l , int r , int rt){
	int m = (l+r)>>1;
	lazy[rt<<1] += lazy[rt] , lazy[rt<<1|1] += lazy[rt];
	seg[rt<<1] += lazy[rt] * (m-l+1) , seg[rt<<1|1] += lazy[rt]*(r-m);
	lazy[rt] = 0;
}

int query(int L , int R , int l , int r , int rt){
	if(l != r && lazy[rt]) push(l , r , rt);
	if(L <= l && R >= r) return seg[rt];
	int m = (l+r)>>1;
	if(R <=m) return query(L , R , l , m , rt<<1);
	if(L > m) return query(L , R , m+1 , r , rt<<1|1);
	return query(L , R , l , m , rt<<1) + query(L , R , m+1 , r , rt<<1|1);
}
void modify(int L , int R , int l , int r , int rt , int x){
	if(l!=r && lazy[rt]) push(l , r , rt);
	if(L <= l && R >= r) 
		return seg[rt] += (r-l+1)*x , lazy[rt] += x , void();
	int m = (l+r)>>1;
	if(L <= m) modify(L , R , l , m , rt<<1 , x);
	if(R >  m) modify(L , R , m+1 , r , rt<<1|1 , x);
	seg[rt] = seg[rt<<1] + seg[rt<<1|1];
}
signed main(){__IO
	int n;
	cin >> n;
	build(1 , n , 1);
	int q;
	cin >> q;
	while(q--){
		int v;
		cin >> v;
		if(v == 1){
			int x , y , k;
			cin >> x >> y >> k;
			modify(x , y , 1 , n , 1 , k);
		}
		else{
			int x , y;
			cin >> x >> y;
			cout << query(x , y , 1 , n , 1) << '\n';
		}
	}
}