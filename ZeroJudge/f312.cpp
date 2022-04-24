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
	int a1,b1,c1,a2,b2,c2,n;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> n;
	int mx = -4e18;
	for(int i=0 ; i<=n ; ++i){
		int x1 = i , x2 = n-i;
		int y1 = a1 * x1 * x1 + b1 * x1 + c1;
		int y2 = a2 * x2 * x2 + b2 * x2 + c2;
		mx = max(mx , y1+y2);
	}
	cout << mx << '\n';
}