#include<cstdio>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
inline int read(){
	int res=0; char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return res;
}
const int maxn = 1e5+5;
int seg[22][maxn*5];
bool lazy[22][maxn*5];
void build(int l , int r , int rt){
	if(l == r){
		int x=read();
		for(int i=0 ; i<22 ; ++i){
			seg[i][rt] = (x>>i)&1;
		}
		return ;
	}
	int m = (l+r)>>1;
	build(l , m , rt<<1);
	build(m+1 , r , rt<<1|1);
	for(int i=0 ; i<22 ; ++i){
		seg[i][rt] = seg[i][rt<<1] + seg[i][rt<<1|1];
	}
}
void push(int l , int r , int rt){
	if(l == r) return;
	int m = (l+r)>>1;
	for(int id=0 ; id<22 ; ++id){
		if(!lazy[id][rt]) continue;
		seg[id][rt<<1] = (m-l+1)-seg[id][rt<<1];
		seg[id][rt<<1|1] = (r-m)-seg[id][rt<<1|1];
		lazy[id][rt<<1] ^= 1;
		lazy[id][rt<<1|1] ^= 1;
		lazy[id][rt] = 0;
	}
}
void modify(int l , int r , int ql , int qr , int rt , int xo){
	push(l , r , rt);
	if(ql <= l and r <= qr){
		for(int id=0 ; id<22 ; ++id){
			if(xo>>id & 1){
				seg[id][rt] = (r-l+1)-seg[id][rt];
				lazy[id][rt] ^= 1;		
			}
		}
		return;
	}
	int m = (l+r)>>1;
	if(ql <= m) modify(l , m , ql , qr , rt<<1 , xo);
	if(qr > m) modify(m+1 , r , ql , qr , rt<<1|1 , xo);
	for(int id=0 ; id<22 ; ++id)
		seg[id][rt] = seg[id][rt<<1] + seg[id][rt<<1|1];
}
long long query(int l , int r , int ql , int qr , int rt){
	push(l , r , rt);
	if(ql <= l and r <= qr){
		long long res = 0ll;
		for(int id=0 ; id<22 ; ++id){
			res += seg[id][rt] * (1ll<<id);
		}
		return res;
	}
	int m = (l+r)>>1;
	if(qr <= m) return query(l , m , ql , qr , rt<<1);
	if(ql > m) return query(m+1 , r , ql , qr , rt<<1|1);
	return query(l , m , ql , qr , rt<<1) + query(m+1 , r , ql , qr , rt<<1|1);
}
signed main(){
	int n=read();
	build(1 , n , 1);
	int q=read();
	while(q--){
		int type=read();
		if(type == 2){
			int l=read() , r=read() , xo=read();
			if(l > r){
				int t = l; l = r , r = t;
			}
			modify(1 , n , l , r , 1 , xo);
		}
		else{
			int l=read() , r=read();
			if(l > r){
				int t = l; l = r , r = t;
			}
			printf("%lld\n",query(1 , n , l , r , 1));
		}
	}
}