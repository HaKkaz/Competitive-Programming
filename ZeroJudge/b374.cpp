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
map<int,int> cnt;
int a[1005];
signed main(){
	IOS;
	int n;
	cin >> n ;
	int x;
	vector<pii> ans;
	for(int i=1 ; i<=n ; ++i) cin >> x , cnt[x]++;
	for(auto &c : cnt) ans.push_back({c.S , c.F});
	sort(all(ans)),reverse(all(ans));
	int what = ans[0].F;
	vector<int> all;
	for(int i=0 ; i<sz(ans) ; ++i){
		if(ans[i].F == what) all.push_back(ans[i].S);
	}
	sort(all(all));
	for(int &c : all) cout << c << ' ' << what << '\n';
}