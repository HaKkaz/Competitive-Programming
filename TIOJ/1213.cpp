#include<bits/stdc++.h>
#define test_
#define PB push_back
#define S second
#define F first
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
typedef pair<int,int> pii;
vector<pii> v[100005];
bitset<100005> vis;
vector<int> dist(100005,0);
void dfs(int now , int dis){
	vis[now] = 1 , dist[now] = dis;
	for(int i=0 ; i<(int)v[now].size() ; ++i){
		if(!vis[v[now][i].F]) vis[v[now][i].F] = 1,dfs(v[now][i].F , dis+v[now][i].S);
	}
}
int n; 
void init(){
	for(int i=0 ; i<=n ; ++i) v[i].clear();
}
int main(){
	__IO;
	while(cin >> n&&n){
		init();
		vis.reset();
		for(int i=0 ; i<n-1 ; ++i){
			int x , y , w; cin >> x >> y >> w;
			v[x].push_back({y , w});
			v[y].push_back({x , w});
		}
		dfs(1 , 0);
		int mx=0 , ed;
		for(int i=1 ; i<=n ; ++i) if(mx < dist[i]) mx=dist[i] , ed = i;
		vis.reset();
		dfs(ed , 0);
		mx = 0;
		for(int i=1 ; i<=n ; ++i) if(mx < dist[i]) mx=dist[i] , ed = i;
		cout << dist[ed] << '\n';
	}
	return 0;
}