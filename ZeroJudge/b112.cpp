#include<bits/stdc++.h>
#define test_
#define pb push_back
#define S second
#define F first
#define Sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
long long ans = 0;
int n , m , cnt , need , j;
bool G[21][21] , g[21] , vis[21];
inline void init(){
	for(int i=0 ; i<21 ; ++i)
		for(int j=0 ; j<21 ; ++j)
			G[i][j] = 0;
	for(int i=0 ; i<21 ; ++i) g[i] = vis[i] = 0;
	ans = cnt = need = j = 0;
}
void dfs(int now){
	vis[now] = 1;
	++cnt;
	for(int i=1 ; i<=n ; ++i){
		if(g[i] && G[now][i] && vis[i] == 0) dfs(i);
	}
}
inline void solve(){
	for(int i=1 ; i<(1<<n) ; ++i){
		j = i , cnt = 0 , need = 0;
		for(int i=1 ; i<=n ; ++i) g[i] = 0 , vis[i] = 0;
		for(int i=1 ; i<=n ; ++i , j>>=1){
			if(j&1) g[i] = 1 , ++need;
		}
		for(int i=1 ; i<=n ; ++i){
			if(g[i]){
				dfs(i);
				break;
			}
		}
		if(cnt == need) ++ans;
	}
}
int main(){
//__IO
	int n;
	while(cin >> n){
	int now = -1111;
	for(int i=1 ; i<=n ; ++i){
		int x; cin >> x;
		if(now < 0) now = x;
		else{
			now = __gcd(x , now);
		}
	}
	cout << now << '\n';
}}