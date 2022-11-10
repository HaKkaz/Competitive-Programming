#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int maxn = (1<<13);
int dp[(1<<13)];
vector<pii> v;
inline void check(int a,int b){
	v.push_back({a,b});
}
bool dfs(int now){
	if(dp[now]!=-1) return dp[now];
	bool ok = 0;
	for(int i=0 ; i<13 ; ++i){
		if((now >> i) & 1) ok |= !dfs(now ^ (1<<i));
	}
	for(pii &_to : v){
		if(((now>>_to.F)&1) and ((now>>_to.S)&1)) ok |= !dfs(now^(1<<_to.F)^(1<<_to.S));
	}
	dp[now] = ok;
	return ok;
}
signed main(){
	IOS;
	int t=1;
	check(0,2);
	check(0,3);
	check(1,2);
	check(1,5);
	check(2,5);
	check(5,8);
	check(5,9);
	check(8,9);
	check(5,6);
	check(6,9);
	check(9,12);
	check(10,12);
	check(9,10);
	check(6,10);
	check(6,7);
	check(7,10);
	check(7,11);
	check(10,11);
	check(4,7);
	check(3,4);
	check(2,6);
	check(2,3);
	check(3,6);
	check(3,7);
	fill(dp , dp+(1<<13) , -1);
	dp[0]=1;
	dfs((1<<13)-1);
	while(cin >> t){
		while(t--){
			int now ; cin >> now;
			cout << dp[now]<< ' ' ;
		}
		cout << '\n';
	}
}
// 1 1664