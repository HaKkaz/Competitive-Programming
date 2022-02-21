#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 500001;
int out[maxn] , ans1[maxn] , mx1 , mx2;
vector<int> v[maxn];
inline void latina(){
	loli;
	int t; cin >> t;
	while(t--){
		int n ,e;
		cin >> n>> e;
		for(int i=0 ; i<n ; ++i) v[i].clear();
		fill(out,out+n,0);
		fill(ans1,ans1+n,0);
		mx1=mx2=0;
		for(int i=0 ; i<e ; ++i){
			int a , b;
			cin >> a >> b ;
			v[a].pb(b) , v[b].pb(a);
			out[a]++,out[b]++;
			ans1[min(a,b)]++;
		}
		for(int i = 0 ; i < n ; ++i) mx1 = max(mx1 , ans1[i]);
		priority_queue<pii , vector<pii> , greater<pii>> pq;
		for(int i = 0 ; i < n ; ++i) pq.push({out[i] , i});
		while(pq.size()){
			int now = pq.top().S , deg = pq.top().F;
			pq.pop();
			if(out[now] == 0)continue;
			mx2 = max(mx2 , deg);
			out[now]=0;
			for(int &c : v[now]){
				if(out[c]){
					out[c]--;
					pq.push({out[c] , c});
				}
			}
		}
		cout << mx1 << ' ' << mx2 << '\n';
	}
}
signed main(){latina();}