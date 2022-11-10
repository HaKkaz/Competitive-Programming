#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define rz(n) resize(n)
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
#define LINE cout << "-----------------------\n";
using namespace std;
const int inf = numeric_limits<int>::max();
const int maxn = 1e6+500;
map<int,int> ans;
bool cmp(const pii &a , const pii &b){
	if(a.F != b.F) return a.F > b.F;
	else return a.S < b.S;
}
inline void solve(){
	IOS;
	int n , m ; cin >> n >> m ;
	for(int i=0 ; i<n ; ++i) ans[i]+=0;
	while(m--){
		int a,  b; cin >> a >> b;
		ans[a]+=b;
	}
	vector<pii> v;
	for(auto &c : ans) v.push_back({c.S,c.F});
		sort(all(v),cmp);
	for(auto &c : v) cout << c.S << ' ' << c.F << '\n';
}
signed main(){solve();}