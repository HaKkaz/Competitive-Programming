#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
vector<int> v[1000007];
bitset<1000007> vis;
int a , b , ok=0;
inline void init(int n){
	for(int i=1 ; i<=n ; ++i) v[i].clear();
	vis.reset();
	ok = 0;
}
inline void dfs(int now){
	vis[now] = true;
	if(now == b){
		ok = 1;
		return;
	}
	for(int i=0 ; i<v[now].size() ; ++i){
		if(vis[v[now][i]]) continue;
		dfs(v[now][i]);
	}
}
int main(){
__IO
	int n , m;
	while(cin >> n >> m){
		init(n);
		for(int i=0 ; i<m ; ++i){
			int x , y; cin >> x >> y;
			v[x].PB(y);
		}
		cin >> a >> b ;
		dfs(a);
		if(ok) puts("Yes!!!");
		else puts("No!!!");
	}

}