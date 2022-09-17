#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define S second
#define F first
#define sz(x) (int)(x).size()
#define rz(n) resize(n)
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
using namespace std;
const int inf = 2e18;
const int maxn = 1e6+500;
signed main(){IOS;
	int n , m , tot = 0;
	cin >> n >> m ;
	vector<int> v;
	for(int i=0 ; i<n ; ++i){
		int mx = 0;
		for(int j=0 ; j<m ; ++j){
			int x; cin >> x;
			mx = max(mx , x);
		}
		v.push_back(mx);
		tot += mx;
	}
	cout << tot << '\n';
	vector<int> ans;
	for(auto &c : v){
		if(tot % c == 0) ans.push_back(c);
	}
	if(ans.empty()) cout << -1;
	else{
		for(int i=0 ; i<(int)ans.size() ; ++i){
			cout << ans[i] << " \n"[i==(int)ans.size()-1];
		}
	}
}