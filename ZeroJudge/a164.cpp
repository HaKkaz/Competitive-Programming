#include<bits/stdc++.h>
#define test_
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define et cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;

const int maxn = 2e5+500;
struct node 
{
	int l , r , mx , mn , sum , mxpos , mnpos;
	node operator+(const node &R)const{
		node ans;
		if(mx >= R.mx) ans.mx = mx   , ans.mxpos = mxpos;
		else ans.mx = R.mx , ans.mxpos = R.mxpos;
		if(mn <= R.mn) ans.mn = mn   , ans.mnpos = mnpos;
		else ans.mn = R.mn , ans.mnpos = R.mnpos;
		if(sum >= R.sum && sum >= R.mx - mn){
			ans.sum = sum;
			ans.l = l;
			ans.r = r;
		}
		else if(R.mx - mn > sum && R.mx - mn >= R.sum){
			ans.sum = R.mx - mn;
			ans.l = mnpos+1;
			ans.r = R.mxpos;
		}
		else{
			ans.sum = R.sum;
			ans.l = R.l;
			ans.r = R.r;
		}
		return ans;
	}
}seg[maxn*4] ;
int num[maxn] , pre[maxn];
void build(int l , int r , int rt){
	if(l == r){
		seg[rt].sum = pre[l]-pre[l-1];
		seg[rt].mx  = pre[l];
		seg[rt].l = seg[rt].r = seg[rt].mxpos = l;
		seg[rt].mn  = pre[l-1];
		seg[rt].mnpos = l-1;
		return ;
	}
	int m = (l+r)>>1;
	build(l , m , rt<<1);
	build(m+1 , r , rt<<1|1);
	seg[rt] = seg[rt<<1] + seg[rt<<1|1];
}
node query(int L , int R , int l , int r , int rt){
	if(L <= l && R >= r) return seg[rt];
	int m = (l+r)>>1;
	if(R <= m) return query(L , R , l   , m , rt<<1);
	if(L > m)  return query(L , R , m+1 , r , rt<<1|1);
	return query(L , R , l , m , rt<<1) + query(L , R , m+1 , r , rt<<1|1);
}
int main(){__IO
	int n , q , cnt = 1;
	while(cin >> n >> q){
		for(int i=0 ; i<=n ; ++i) pre[i] = 0;
		cout << "Case "<<cnt++<<":\n";
		for(int i=1 ; i<=n ; ++i) cin >> num[i];
		for(int i=1 ; i<=n ; ++i) pre[i] = pre[i-1]+num[i];
		build(1 , n , 1);
		while(q--){
			int l , r;
			cin >> l >> r;
			node ans = query(l , r , 1 , n , 1);
			cout<< ans.l << ' ' << ans.r << ' ' << ans.sum << '\n';
		}
	}
}