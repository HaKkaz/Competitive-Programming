#include"bits/stdc++.h"
#define pb push_back
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define LINE cout<<"--------------------------\n";
#define IOS ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 1e6+50;
signed main(){
	IOS;
	int n , m ;
	cin >> m;
	while(m--){
		cin >> n;
		int x = 1 , ans = 0;
		for(int i=1 ; i<=n ; ++i){
			x *= 10  , ans += x/17;
			if(i!=n) x%=17;
		}
		cout << x/17 << ' ' << ans << '\n';
	}
}