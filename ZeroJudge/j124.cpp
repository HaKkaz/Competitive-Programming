#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using ll = long long;

int v[1000050];
int i,top;
ll ans;
void dfs(int fa){
	int cur = v[i];
	int cnt = (v[i] & 1 ? 3 : 2);
	if(v[i] == 0) return;
	ans += abs(v[i] - fa);
	while(cnt--){
		++i,dfs(cur);
	}
}

signed main(){
	fast;
	int x;
	while(cin >> x) v[top++]=x;

	dfs(v[0]);

	cout << ans << '\n';
}