#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int maxn = 2e5;
int st[maxn<<2];
void build(int l , int r , int rt){
	if(l == r){
		cin >> st[rt];
		if(st[rt] > 0) st[rt] = 1;
		if(st[rt] < 0) st[rt] = -1;
		return;
	}
	int mid = (l+r)>>1;
	build(l , mid , rt<<1);
	build(mid+1 , r , rt<<1|1);
	st[rt] = st[rt<<1] * st[rt<<1|1];
}
void mdy(int l , int r , int rt , int pos , int k){
	if(l == r && l == pos){
		st[rt] = k;
		if(st[rt] > 0) st[rt] = 1;
		if(st[rt] < 0) st[rt] = -1;
		return;
	}
	int mid = (l+r)>>1;
	if(pos <= mid) mdy(l , mid , rt<<1 , pos , k);
	else mdy(mid+1 , r , rt<<1|1 , pos , k);
	st[rt] = st[rt<<1] * st[rt<<1|1];
}
int qry(int l , int r , int rt , int ql , int qr){
	if(ql <= l && r <= qr) return st[rt];
	int mid = (l+r)>>1;
	if(qr <= mid) return qry(l , mid , rt<<1 , ql , qr);
	else if(ql > mid) return qry(mid+1 , r , rt<<1|1 , ql , qr);
	else return qry(l , mid , rt<<1 , ql , qr)*qry(mid+1 , r , rt<<1|1 , ql , qr);
}
signed main(){
	IOS;
	int n , q; 
	while(cin >> n >> q){
		build(1 , n , 1);
		while(q--){
			char c;
			cin >> c;
			if(c == 'C'){
				int pos , k ; cin >> pos >> k;
				mdy(1 , n , 1 , pos , k);
			}
			if(c == 'P'){
				int l , r; cin >> l >> r;
				int x = qry(1 , n , 1 , l , r);
				if(x > 0) cout << '+';
				if(x < 0) cout << '-';
				if(x == 0) cout << '0';
			}
		}	
		endl
	}
	
}