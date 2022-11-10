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
	int n , k , w;
	cin >> n >> k >> w;
	int ans = n;
	while(n>=k){
		int tmp = n/k;
		ans += tmp*w;
		n %= k;
		n += tmp*w;
	}
	cout << ans << '\n';
}