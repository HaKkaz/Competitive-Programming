#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int const MAXN = 500005;
int ans;
vector<int> v[40005] , lr(MAXN);
inline void init(int n){
	ans = 0 ;
	for(int i=1 ; i<=n ; ++i) v[i].clear();	
	for(int i=1 ; i<=n ; ++i) lr[i]=0;
}
inline void dfs(int now , int color){
	lr[now] = color;
	for(int i=0 ; i<v[now].size()&&!ans ; ++i){
		if(lr[v[now][i]] != 0){
			if(lr[v[now][i]] == lr[now]){
				 ans = 1 ;	break;
			}
			else continue;
		}
		else dfs(v[now][i] , -color);
	}
}
int main(){
__IO
	int n , m ,x , y; 
	while(cin >> n >> m){
		init(n);
		if(!n&&!m) return 0;
		for(int i=0 ; i<m ; ++i) cin >> x >> y , v[x].PB(y) , v[y].PB(x);
		for(int i=1 ; i<=n ; ++i) if(lr[i] == 0) dfs(i , 1);
		if(ans) cout<<"No\n";
		else cout<<"Yes\n";
	}
}