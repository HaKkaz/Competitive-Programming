#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
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
vector< pii > edges[10005];
vector< int > v[20005];
bool bad[20005];
int color[20005];
bool dfs(int now){
	bool gg = false;
	for(int &c : v[now]){
		if(!color[c]){
			color[c] = 3-color[now];
			gg |= dfs(c);
		}
		else if(color[c] == color[now]){
			gg = true;
		}
	}
	return gg;
}
signed main(){
	IOS;
	int n , m;
	cin >> n >> m ;
	for(int i=0 ; i<m ; ++i){
		int a,b; cin >> a >> b;
		++a,++b;
		edges[0].emplace_back(a,b);
	}
	int p , k;
	cin >> p >> k;
	for(int i=1 ; i<=p ; ++i){
		for(int j=0 ; j<k ; ++j){
			int a,b; cin >> a >> b;
			++a,++b;
			edges[i].emplace_back(a,b);
		}
	}
	while(1){
		int l = 0 , r = p+1;
		while(l < r){
			int mid = (l + r)/2;
			//init
			for(int i=1 ; i<=n ; ++i){
				color[i] = 0;
				v[i].clear();
			}
			//addedge
			for(int i=0 ; i<=mid ; ++i){
				if(!bad[i]){
					for(pii pr : edges[i]){
						int a = pr.F , b = pr.S;
						v[a].emplace_back(b);
						v[b].emplace_back(a);
					}
				}
			}
			bool gg = false;
			for(int i=1 ; i<=n ; ++i) {
				if(!color[i]) {
					color[i] = 1;
					gg |= dfs(i);
				}
			}
			if(!gg) l = mid+1;
			else r = mid;
		}
		if(l == p+1) break;
		bad[l] = 1;
		cout << l << '\n';
	}
}