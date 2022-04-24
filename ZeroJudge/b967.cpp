#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define rz(n) resize(n)
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
using namespace std;
const int inf = numeric_limits<int>::max();
const int maxn = 1e6+500;
vector<int> v[maxn];
int dis[maxn] , pt, mx;
void dfs(int now , int d){
	dis[now] = d;
	if(d > mx) pt = now , mx = d;
	for(auto &c : v[now]){
		if(!dis[c])
			dfs(c , d+1);
	}
}
signed main(){IOS;
	int n;
	while(cin >> n){
		pt = -1 , mx = 0;
		for(int i=0 ; i<n ; ++i) v[i].clear() , dis[i] = 0;
		for(int i=0 ; i<n-1 ; ++i){
			int a , b;
			cin >> a >> b ;
			v[a].pb(b);
			v[b].pb(a);
		}
		dfs(0 , 1);
		fill(dis , dis+n+1 , 0);
		int st = pt;
		pt = -1 , mx = 0;
		dfs(st , 1);
		cout << mx-1 << '\n';
	}
}