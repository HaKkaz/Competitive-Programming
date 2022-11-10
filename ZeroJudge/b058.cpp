#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
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
set<int> out;
queue<int> q;
int w[10005] , n , m , in[10005] , vmax[10005];
vector<int> v[10005] ,  vmain[10005];
void dfs(int now){
	for(auto &c : v[now]){
		--in[c];
		if(!in[c]) q.push(c);
		if(w[c]+vmax[now] > vmax[c]) vmax[c] = w[c]+vmax[now] , vmain[c].clear() , vmain[c].PB(now);
		else if(w[c]+vmax[now] == vmax[c]) vmain[c].PB(now);
	}
}
void dfs2(int now){
	out.insert(now);
	for(auto &c:vmain[now]) dfs2(c);
}
inline void solve(){
	int mx = 0;
	for(int i=1 ; i<=n ; ++i) if(!in[i]) q.push(i);
	while(q.size()){
		int x = q.front();q.pop();
		dfs(x);
	}
	for(int i=1 ; i<=n ; ++i) if(!v[i].size()) mx = max(mx , vmax[i]);
	for(int i=1 ; i<=n ; ++i)if(vmax[i] == mx) dfs2(i);
	cout << out.size() <<'\n';
}
inline void init(int n){
	for(int i=0 ; i<n ; ++i) in[i] = 0 , w[i] = 0 , v[i].clear() , vmain[i].clear() , vmax[i] = 0 ;
	out.clear();
}
int main(){
//__IO
	while(cin >> n >> m){
	init(10005);
		for(int i=1 ; i<=n ; ++i) cin >> w[i] , vmax[i] = w[i];
		for(int i=0 ; i<m ; ++i){
			int a , b; cin >> a >> b ;
			v[a].PB(b) , ++in[b];
		}
		solve();
	}
}