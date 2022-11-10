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
pii a[1000005];
signed main(){
	IOS;
	int n; cin >> n ;
	for(int i=1 ; i<=n ; ++i) cin >> a[i].S;
	a[1].F=a[1].S , a[n].F=a[n].S;
	for(int i=2 ; i<=n-1 ; ++i){
		a[i].F = a[i-1].S + a[i+1].S;
	}
	sort(a+1 , a+n+1);
	for(int i=1 ; i<= n ; ++i) cout << a[i].F << ' ' << a[i].S << '\n';
}