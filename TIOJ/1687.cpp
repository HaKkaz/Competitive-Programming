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
int n , q , L , ac[30][100005] , depth[100005] , in[100005] , out[100005] , cnt = 0;
vector<int> v[100005];
void dfs(int now , int last , int d){
	in[now] = ++cnt;
	for(auto &c:v[now])
		if(c != last)
			depth[c] = d+1 , ac[0][c] = now , dfs(c , now , d+1);
	out[now] = cnt;
}
inline void build(){
	ac[0][1] = 1;
	L = __lg(n);
	for(int i=1 ; i<=L ; ++i)
		for(int j=1 ; j<=n ; ++j)
			ac[i][j] = ac[i-1][ac[i-1][j]];
}
inline bool ancestor(int a , int b){
	if(in[a]<=in[b] && out[a]>=out[b]) return true;
	return false;
}

inline int findLCA(int a , int b){
	if(ancestor(a , b)) return a;
	if(ancestor(b , a)) return b;
	for(int i=L ; i>=0 ; --i){
		if(!ancestor(ac[i][a] , b)) a = ac[i][a];
	}
	return ac[0][a];
}
inline int query(int a , int b , int dis){
	int _LCA = findLCA(a , b) , LCAtoa = depth[a]-depth[_LCA];
	int _tot = depth[a]+depth[b]-2*depth[_LCA];
	if(dis == 0) return a;
	if(dis == _tot) return b;

	if(dis > _tot) return -1;
	if(dis > LCAtoa){
		int d = depth[_LCA] + (dis - LCAtoa);
		for(int i=L ; i>=0 ; --i){
			if(depth[ac[i][b]] > d && ancestor(ac[i][b] , b)) b = ac[i][b];
		}
		return ac[0][b];
	}
	else{
		int d = depth[a] - dis;
		for(int i=L ; i>=0 ; --i){
			if(depth[ac[i][a]] > d && ancestor(ac[i][a] , a)) a = ac[i][a];
		}
		return ac[0][a];
	}
}
int main(){
__IO
	cin >> n >> q ;
	for(int i=0 ; i<n-1 ; ++i){
		int a , b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs(1, 0 , 0);
	build();
	while(q--){
		int a , b , c;
		cin >> a >> b >> c;
		cout<<query(a , b , c)<<'\n';
	}
}