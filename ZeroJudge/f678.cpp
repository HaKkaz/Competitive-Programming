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
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
struct Edge
{
	int a , b , w;
	Edge(int _a , int _b , int _w):a(_a) , b(_b) , w(_w){}
	Edge(){}
	bool operator<(const Edge &tmp)const{
		return w < tmp.w;
	}
};
vector<Edge> Es;
int fa[1000005];
int Find(int x){
	if(x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
}
bool Union(int a , int b){
	a = Find(a) , b = Find(b);
	if(a == b) return 1;
	fa[b] = a;
	return 0;
}
signed main(){
	IOS;
	int n, m;
	cin >> n >> m ;
	for(int i=0 ; i<n ; ++i) fa[i]=i;
	for(int i=0 ; i<m ; ++i){
		int a,b,w; 
		cin >> a >> b >> w;
		Es.pb({a,b,w});
	}
	sort(all(Es));
	int ans = 0;
	for(int i=0 ; i<m ; ++i){
		if(!Union(Es[i].a , Es[i].b)){
			ans += Es[i].w;
		}
	}
	cout << ans << '\n';
}