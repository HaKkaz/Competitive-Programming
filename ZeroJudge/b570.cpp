#include<iostream>
#include<bitset>
#include<set>
#include<vector>
#include<algorithm>
#include<utility>
#define __IO ios::sync_with_stdio(false),cin.tie(0);
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
using namespace std;
int f[1000005] , child[1000005] , ans;

inline void init(){
	for(int i=0 ; i<1000005 ; ++i) f[i] = i , child[i] = 1;
	ans=0;
}

inline int find(int x){
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
inline void Union(int a , int b){
	a = find(a) , b = find(b);
	if(a == b) return;
	if(child[a] < child[b]) swap(a , b);
	f[b] = a;
	child[a] += child[b];
	--ans;
}
bitset<1000005> used;
int main(){__IO
	init();
	int n , m , a, b; cin >>n >>m;
	vector<int> brk , out;
	vector<pii> p;
	p.pb(mp(0,0));
	for(int i=1 ; i<=m ; ++i) cin >> a >> b ,  p.pb(mp(a,b));
	int q; cin >> q;
	for(int i=0 ; i<q ; ++i){
		int x; cin >> x;
		brk.pb(x);
		used[x] = 1;
	}
	for(int i=1 ; i<=m ; ++i) if(!used[i]) Union(p[i].F , p[i].S);
	for(int i=1 ; i<=n ; ++i) find(i);
	set<int> s;
	for(int i=1 ; i<=n ; ++i) s.insert(f[i]);
	ans = s.size();
	out.pb(ans);
	for(int i=brk.size()-1 ; i>=0 ; --i){
		Union(p[brk[i]].F , p[brk[i]].S);
		out.pb(ans);
	}
	for(int i=out.size()-2 ; i>=0 ; --i) cout<<out[i]<<'\n';
}