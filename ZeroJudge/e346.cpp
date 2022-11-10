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
const int maxn = 1e6+5000;
int a[maxn];
signed main(){
	IOS;
	int n;
	cin >> n ;
	for(int i=1 ; i<=n ; ++i) cin >> a[i] , a[i] += a[i-1];
	int q; cin >> q;
	while(q--){
		int l ,r ; cin >> l >> r ;
		cout << a[r] - a[l-1] << '\n';
	}
}