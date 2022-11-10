#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math")
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
const int MaxN = 1000000+5;
const int MaxQ = 100000+5;
int A[MaxN];
bool C[MaxQ];
int X[MaxQ] , Y[MaxQ], Z[MaxQ];
int k,m,N,Q;
int tree[MaxN<<2] , mx[MaxN<<2] , mn[MaxN<<2] , lazy[MaxN<<2];
void pull(int rt){
	tree[rt] = (tree[rt<<1] + tree[rt<<1|1]) % m;
	mx[rt] = max(mx[rt<<1] , mx[rt<<1|1]);
	mn[rt] = min(mn[rt<<1] , mn[rt<<1|1]);
}
void build(int l , int r , int rt){
    if(l == r) return tree[rt] = mx[rt] = mn[rt] = A[l] /*, cout << l << " = " << tree[rt] << ' ' << mx[rt] << ' ' << mn[rt] << '\n'*/,void();
    int mid = (l+r)>>1;
    build(l , mid , rt<<1);
    build(mid+1 , r , rt<<1|1);
    pull(rt);
}
void push(int l , int r , int rt){
    if(l == r || lazy[rt] == -1) return;
    int mid = (l+r)>>1;
    lazy[rt<<1] = lazy[rt];
    lazy[rt<<1|1] = lazy[rt];
    tree[rt<<1] = (mid-l+1)*lazy[rt]%m;
    tree[rt<<1|1] = (r-mid)*lazy[rt]%m;
    mx[rt<<1] = mx[rt<<1|1] = lazy[rt];
    mn[rt<<1] = mn[rt<<1|1] = lazy[rt];
    lazy[rt] = -1;
}
void modify(int l , int r , int rt , int ql , int qr , int k){
    push(l , r , rt);
    if(ql <= l && r <= qr){
    	lazy[rt] = k;
    	tree[rt] = (r-l+1)*k%m;
    	mx[rt] = k;
    	mn[rt] = k;
    	return;
    }
    int mid = (l+r)>>1;
    if(ql <= mid) modify(l , mid , rt<<1 , ql , qr , k);
    if(qr >  mid) modify(mid+1 , r , rt<<1|1 , ql , qr , k);
    pull(rt);
}
#define piii pair<int,pair<int,int>>
piii query(int l , int r , int rt , int ql , int qr){
	push(l,r,rt);
    if(ql <= l && r  <= qr) return piii(tree[rt],pii(mx[rt],mn[rt]));
    int mid = (l+r)>>1;
    const int inf = 1e9;
    piii qa={0,{-inf,inf}} , qb={0,{-inf,inf}};
    if(qr <= mid) qa = query(l , mid , rt<<1 , ql , qr);
    else if(ql > mid) qb = query(mid+1 , r , rt<<1|1 , ql , qr);
    else{
    	qa = query(l , mid , rt<<1 , ql , qr);
    	qb = query(mid+1 , r , rt<<1|1 , ql , qr);
    }
    piii res;
    res.F = qa.F + qb.F;
    res.S.F = max(qa.S.F , qb.S.F);
    res.S.S = min(qa.S.S , qb.S.S);
    return res;
}

void gen_dat()
{
   int i,j;
   for( i=k+1; i<=max(Q,N); ++i )
      A[i] = ( A[i-2]*97 + A[i-1]*3 )%m+1;
   for(i=1,j=max(Q,N); i<=Q; ++i,--j)
   {
      C[i] = A[i]&1;
      X[i] = (A[i]+A[j])%N+1;
      Y[i] = X[i]+ ( (A[i]<<3)+(A[j]<<5)+m )%( N-X[i]+1 );
      if(!C[i]) Z[i] = ((A[i]<<3)+(A[j]<<5))%m+1;
   }
}

signed main(){
	IOS;
	cin >> k >> m;
	for(int i=1 ; i<=k ; ++i)cin >> A[i];
	cin >> N >> Q;
	gen_dat();
	fill(lazy , lazy+(MaxN<<2) , -1);
	fill(mx , mx+(MaxN<<2) , -100000);
	fill(mn , mn+(MaxN<<2) , 100000);
	build(1,N,1);
	for(int i=1 ; i<=Q ; ++i){
		if(C[i] == 0){
			modify(1 , N , 1 , X[i] , Y[i] , Z[i]);
		}
		if(C[i] == 1){
			piii ans = query(1 , N , 1 , X[i] , Y[i]);
			cout << ans.F%m << ' ' << ans.S.F - ans.S.S << '\n';
		}
	}
}