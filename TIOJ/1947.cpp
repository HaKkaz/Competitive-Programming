#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define LINE cout<<"--------------------------\n";
using namespace std;
const int maxn = 1e6+5;
vector<int> v[maxn];
int child[maxn] , ans = 1e9,t,n, in[maxn] , out[maxn];
int cent,MN=1e9;
bitset<maxn> vis;
void dfs1(int now){
	child[now]=vis[now]=1;
	int maxc=0;
	for(auto &c : v[now])
		if(!vis[c])
			dfs1(c),child[now]+=child[c],maxc=max(maxc,child[c]);
	maxc = max(maxc , n-child[now]);	
	if(maxc < MN) MN = maxc , cent = now;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n ;
	for(int i=1 ; i<n ; ++i){
		int a , b;
		cin >> a >> b;
		v[a].pb(b),v[b].pb(a);
	}
	vis.reset(),dfs1(0);
	cout << MN << '\n';
}