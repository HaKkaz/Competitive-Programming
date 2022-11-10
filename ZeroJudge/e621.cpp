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
inline void solve(){
	IOS;
	int n; cin >> n ;
	for(int i=0 ;i<n ; ++i){
		int a , b , c;
		cin >> a >> b >> c;
		bool tag=1;
		for(int j=a+1 ; j<b ; ++j){
			if(j%c) cout << j << ' ' , tag=0;
		}
		if(tag) cout << "No free parking spaces.";
		cout << '\n';
	}
}
signed main(){solve();}