#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 500001;
inline void latina(){
	int n;
	while(cin >> n){
		int a[505]; a[1] = 1;
		for(int i=2 ; i<=n ; ++i){
			a[i] = a[i-1] + i-1;
		}
		cout << a[n] << '\n';
	}
}
signed main(){loli;latina();}