#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
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
signed main(){
	IOS;
	vector<pii> dp(1,MP(-2000000000,0));
	vector<int> lst(500005,0),a(500005,0);
	int i = 1 , x;
	while(cin >> x){
		auto it = lower_bound(all(dp) , MP(x,-1));
		if(it == dp.end()){
			lst[i] = dp.back().S;
			dp.push_back(MP(x,i));
		}
		else{
			lst[i] = dp[it-dp.begin()-1].S;
			dp[it-dp.begin()] = MP(x , i);
		}
		a[i++] = x;
	}
	vector<int> ans;
	int now = dp.back().S;
	while(now){
		ans.push_back(a[now]);
		now = lst[now];
	}
	reverse(all(ans));
	cout << ans.size() << "\n-\n";
	for(auto &c : ans) cout << c << '\n';
}