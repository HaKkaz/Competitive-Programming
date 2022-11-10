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
inline void solve(){
	int a , b;
	while(cin >> a >> b and a != -1){
		if(a > b) swap(a , b);
		cout << min(b-a , a-0 + 99-b + 1) << '\n';
	}
}
signed main(){IOS;solve();}