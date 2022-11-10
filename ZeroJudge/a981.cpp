#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3","unroll-loops")
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
#define int long long
using namespace std;
vector<int> v , ans;
int n , m;
bool tag = false;
void dfs(int now , int tot){
	if(now > n) return;
	if(tot == m){
		tag = true;
		for(auto &c : ans) cout << c << ' ';
			cout << '\n';
		return;
	}
	if(tot > m) return;
	ans.pb(v[now]);
	dfs(now+1 , tot + v[now]);
	ans.pop_back();
	dfs(now+1 , tot);
}
signed main(){
__IO
	cin >> n >> m;
	v.resize(n);
	for(int i=0 ; i<n ; ++i){
		cin >> v[i];
	}
	sort(all(v));
	dfs(0 , 0);
	if(!tag) cout << -1 << '\n';
}