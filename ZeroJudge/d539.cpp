//區間最大值 Segment Tree /20181225
#include<iostream>
using namespace std;
const int MAXN = 500000;
struct node{
	int l , r;
	int data;
}seg[MAXN*4];

void build(int l , int r , int rt){
	seg[rt].l = l , seg[rt].r = r;
	if(l == r) return cin >> seg[rt].data , void();//seg[rt].data = num[l];
	int m = (l+r)>>1;
	build(l , m , (rt<<1));
	build(m+1 , r , ((rt<<1)|1));
	seg[rt].data = max(seg[rt<<1].data , seg[((rt<<1)|1)].data); //maximum value
}

int query(int ql , int qr , int l , int r , int rt){
	if(ql <= l && qr >= r) return seg[rt].data;
	int m = (l+r)>>1 , ans = 0;
	if(m >= qr) return query(ql , qr , l , m , rt<<1);
	if(m < ql) return query(ql , qr , m+1 , r , rt<<1|1);
	return max(query(ql , qr , l , m , rt<<1) , query(ql , qr , m+1 , r , rt<<1|1));
}


int main(){ios::sync_with_stdio(false),cin.tie(0);
	int n ; cin >> n ;
	build(1 , n , 1);
	int q ; cin >> q ;
	while(q--){
		int a , b ; cin >> a >> b;
		if(a>b) swap(a,b);
		cout << query(a , b , 1 , n , 1) <<'\n';
	}
}
/*
5
3 6 10 4 9
*/