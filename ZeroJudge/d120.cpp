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
int mx = 0;
inline void solve(){
	int n;
	while(cin >> n && n){
		int N = n;
		set<int> s;
		int now = 2;
		while(n>1){
			if(n % now == 0) n /= now , s.insert(now);
			else ++now;
		}
		cout << N << " : "<< s.size() << '\n';
	}
}
signed main(){IOS;solve();}