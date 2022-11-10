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
	int t; cin >> t;
	while(t--){
		int x1 , y1 , x2 , y2;
		cin >> x1 >> y1 >> x2 >> y2 ;
		int G = __gcd(abs(x2-x1) , abs(y2-y1));
		cout << ++G << '\n';
	}
}
signed main(){loli;latina();}