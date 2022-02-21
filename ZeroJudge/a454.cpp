#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define Sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
#define int long long
const int maxn = 1e3+5;
const int INF = 1e9+7;
int w[maxn] , in[maxn] , dist[maxn] , t , x , _to , n;
vector<int> v[maxn];
queue<int> q;
void init(){
	for(int i=1 ; i<=n ; ++i){
		in[i] = 0;
		dist[i] = -INF;
		v[i].clear();
	}
}
signed main(){
__IO
	int T;
	cin >> T;
	while(T--){
		init();
		cin >> n;
		for(int i=1 ; i<=n ; ++i){
			cin >> t;
			w[i] = t;

			cin >> t;
			for(int j=0 ; j<t ; ++j){
				cin >> _to;
				v[i].pb(_to);
				++in[_to];
			}
		}
		for(int i=1 ; i<=n ; ++i)
			if(in[i] == 0)
				q.push(i) , dist[i] = w[i];
		int ans = 0;
		while(q.size()){
			int now = q.front();
			q.pop();
			for(auto &c : v[now]){
				--in[c];
				if(in[c] == 0) q.push(c);
				dist[c] = max(dist[now]+w[c] , dist[c]);
			}
			ans = max(dist[now] , ans);
		}
		cout << ans << '\n';
	}
}