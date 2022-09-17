#include <bits/stdc++.h>
using namespace std;
vector<int> v[50005];
bool vis[50005];
int ans;
void dfs(int now){
	vis[now] = 1;
	for(auto c : v[now]){
		if(vis[c] == 0){
			dfs(c);
		}
	}
}
int main() {
	int n; cin >> n;
	for(int i=0 ; i<n ; ++i){
		int x; cin >> x;
		v[i].push_back(x);
		v[x].push_back(i);
	}
	for(int i=0 ; i<n ; ++i){
		if(!vis[i]){
			dfs(i);
			ans = ans + 1;
		}
	}
	cout << ans << '\n';
}