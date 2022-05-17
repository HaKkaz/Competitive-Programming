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
vector<int> val[1000005];
signed main(){
	IOS;
	int t ; cin >> t;
	for(int i=0 ; i<t ; ++i){
		int n; cin >> n ;
		//init
		for(int i=1 ; i<=n ; ++i) val[i].clear();
		vector<int> w(n+1,0) , fa(n+1,0) , mx(n+1,0) , in(n+1,0);
		//input
		for(int i=1 ; i<=n ; ++i) cin >> w[i];
		for(int i=1 ; i<=n ; ++i) cin >> fa[i] , in[fa[i]]++;
		//topo
		int ans = 0;
		queue<int> q;
		for(int i=1 ; i<=n ; ++i) if(!in[i]) q.emplace(i);
		while(q.size()){
			int now = q.front(); q.pop();
			int nxt = fa[now];
			if(!val[now].empty()){
				int MN = *min_element(all(val[now]));
				ans -= MN;
				w[now] = max(w[now] , MN);
			}
			ans += w[now];
			if(now == 0) break;
			in[nxt]--;
			val[nxt].emplace_back(w[now]);
			if(!in[nxt]) q.emplace(nxt);
		}
		cout << "Case #" << i+1 << ": "<<ans<<'\n';
	}
}