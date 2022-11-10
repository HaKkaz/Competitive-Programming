#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 1e6+5;
const int INF = 1e9+7;
pii G[1000][1000];
struct edge
{
	int _to , w;
	bool operator<(const edge & a)const{
		return w > a.w;
	}
};
vector<edge> E[maxn];
int dist[maxn] , n , m , x , now;
void build(){
	now = 0;
	for(int i=0 ; i<n ; ++i)
	 	for(int j=0 ; j<m ; ++j)
	 		cin >> G[i][j].F , G[i][j].S = now++;

	for(int i=0 ; i<now ; ++i) E[i].clear();
	for(int i=1 ; i<now ; ++i) dist[i] = INF;

	for(int i=0 ; i<n ; ++i)
	 	for(int j=0 ; j<m ; ++j){
	 		now = G[i][j].S;
	 		if(j-1 >= 0) E[now].pb({G[i][j-1].S , G[i][j-1].F});
	 		if(j+1 <  m) E[now].pb({G[i][j+1].S , G[i][j+1].F});
	 		if(i-1 >= 0) E[now].pb({G[i-1][j].S , G[i-1][j].F});
	 		if(i+1 <  n) E[now].pb({G[i+1][j].S , G[i+1][j].F});
 		}
}
void dijkstra(){
	priority_queue<edge> pq;
	pq.push({0 , G[0][0].F});
	dist[0] = G[0][0].F;
	while(pq.size()){
		int now = pq.top()._to , dis = pq.top().w;
		pq.pop();
		if(dis != dist[now]) continue;
		for(auto &c : E[now]){
			if(c.w + dist[now] < dist[c._to]){
				dist[c._to] = c.w + dist[now];
				pq.push({c._to , dist[c._to]});
			}
		}
	}
 	while(pq.size()) pq.pop();
	cout << dist[now];endl
}
int main(){
__IO
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m ;
		build();
		dijkstra();
	}
}