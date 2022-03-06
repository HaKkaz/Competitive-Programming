#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
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
const int maxn = 2e5+50;
int n , q , C , id[maxn];
struct T
{
	int L , R , ans;
	T(int x){L=R=ans=x;}
	T(){}
};

T up(int lz , int rz, T a, T b){
	T rt;
	if(a.L==lz) rt.L=a.L+b.L;
	else rt.L=a.L;
	if(b.R==rz) rt.R=a.R+b.R;
	else rt.R=b.R;
	rt.ans=max({a.ans,b.ans,a.R+b.L});
	return rt;
}

struct node
{
	node *l , *r;
	T data;
	node(){}
	node(int x){data=T(x),l=r=nullptr;}
}*root[1<<24],mem[maxn<<5];

int memtp=0;

node *lch(node *rt){return rt?rt->l:nullptr;}
node *rch(node *rt){return rt?rt->r:nullptr;}
T get_T(int sz, node *rt){return rt?rt->data:T(sz);}

T query(int l , int r , int ql , int qr , node *rt){
	if(ql <= l && r <= qr)
		return get_T(r-l+1,rt);
	int m = (l+r)>>1;
	if(qr<=m) return query(l,m,ql,qr,lch(rt));
	if(ql>m) return query(m+1,r,ql,qr,rch(rt));
	return up(m-l+1,r-m,query(l,m,ql,qr,lch(rt)),query(m+1,r,ql,qr,rch(rt)));
}

node *modify(int l , int r , int id , node *rt , int k){
	//cout << l << ' ' << r << '\n';
	if(!rt) mem[memtp]=node(r-l+1),rt = &mem[memtp++];
	if(l == r) return rt->data=T(k) , rt;
	int m = (l+r)>>1;
	if(id <= m) rt->l = modify(l , m , id , rt->l , k);
	if(id >  m) rt->r = modify(m+1 , r , id , rt->r , k);
	return rt->data=up(m-l+1 , r-m, get_T(m-l+1, rt->l), get_T(r-m, rt->r)) , rt;
}

inline void latina(){loli;
	cin >> n >> q >> C;
	for(int i=0 ; i<n ; ++	i){
		cin >> id[i];
		root[id[i]] = modify(0 , n-1 , i , root[id[i]] , 0);
	}
	while(q--){
		int kk=0;
		cin >> kk;
		if(!kk){
			int P , K;
			cin >> P >> K;
			root[id[P]] = modify(0 , n-1 , P , root[id[P]] , 1);
			id[P]=K;
			root[id[P]] = modify(0 , n-1 , P , root[id[P]] , 0);
		}
		else{
			int l , r , k;
			cin >> l >> r >> k ;
			cout << query(0 , n-1 , l , r-1 , root[k]).ans << '\n';
		}
	}
}
signed main(){latina();}