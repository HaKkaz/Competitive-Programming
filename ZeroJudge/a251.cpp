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
signed main(){
	IOS;
	int t=1;
	cin >> t;
	while(t--){
		int n,a[50];
		cin >> n ;
		for(int i=0 ; i<4 ; ++i) cin >> a[i];
		for(int i=4 ; i<n ; ++i){
			a[i] = a[i-4] + a[i-1];
		}
		sort(a , a+n);
		cout << a[n/2] << '\n';
	}
}