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
using namespace std;
const int inf = numeric_limits<int>::max();
const int maxn = 1e6+500;
string ans[45];
inline void solve(){
	ans[1] = "1";
	for(int i=2 ; i<=40 ; ++i){
		char p = ans[i-1][0];
		int cnt = 1;
		ans[i] = "";
		for(int j=1 ; j<ans[i-1].size() ; ++j){
			if(ans[i-1][j] == p) ++cnt;
			else ans[i]+=to_string(cnt),ans[i]+=p,cnt=1,p=ans[i-1][j];
		}
		ans[i]+=to_string(cnt),ans[i]+=p;
	}
	int n;
	while(cin >> n ) cout << ans[n] << '\n';
}
signed main(){IOS;solve();}