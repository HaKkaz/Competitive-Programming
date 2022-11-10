#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
const int maxn = 5e4+50;
vector<int> v[maxn];
int in[maxn] , out[maxn] , a[maxn] , dft;
void dfs(int now , int fa){
	in[now] = ++dft;
	for(int &c : v[now]){
		if(c != fa){
			dfs(c , now);
		}
	}
	out[now] = dft;
}
//BIT
int bit[maxn];
void upd(int i , int k){
	for( ; i < maxn ; i += (i&(-i)))
		bit[i] += k;
}
int qry(int i){
	int res =0  ; 
	for( ; i ; i -= (i & (-i)))
		res += bit[i];
	return res;
}
signed main(){
	IOS;
	int n; cin >> n ;
	fill(a+1 , a+n+1 , 1);
	for(int i=1 ; i<=n ; ++i) upd(i , 1);
	for(int i=1 ; i<n ; ++i){
		int a,b; cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1 , 1);
	int q; cin >> q;
	while(q--){
		int opt , x; cin >> opt >> x;
		if(opt == 1){
			if(a[x]) upd(in[x] , -1);
			else upd(in[x] , 1);
			a[x] ^= 1; 
		}
		if(opt == 2){
			cout << qry(out[x]) - qry(in[x]-1) << '\n';
		}
	}
}