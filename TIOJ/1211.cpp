#include<bits/stdc++.h>
using namespace std;
long long  f[10005] , n , m , a , b , w , tot , cnt;
struct edge
{
	long long a , b , w;
	bool operator<(const edge &x)const{
		return w<x.w;
	}
};
vector<edge> v;
void init(int n){
	for(int i=1 ; i<=n ; ++i) f[i]=i;
	v.clear() , tot = 0 , cnt = 0;
}
int query(int x){
	if(x == f[x]) return x;
	return f[x] = query(f[x]);
}
bool U(int a , int b){
	a = query(a) , b = query(b);
	return ((a == b) ? false : f[b] = f[a]);
}
using namespace std;
int main(){ios::sync_with_stdio(false),cin.tie(0);
	while(cin >> n >> m&&n&&m){
		v.clear() , init(n);
		for(int i=0 ; i<m ; ++i) cin >> a >> b >> w , v.push_back({a , b , w});		
		sort(v.begin(),v.end());
		for(int i = 0 ; i<m ; ++i) if(U(v[i].a , v[i].b)) tot += v[i].w , ++cnt;
		cout << (cnt == n-1 ? tot : -1) <<'\n';
	}
}