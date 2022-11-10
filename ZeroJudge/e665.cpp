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
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int maxn = 500001;
int a , b , c;
inline void latina(){
	loli;
	int n; cin >> n;
	for(int i=1,now=1 ; i<=n ; ++i,now<<=1){
		a+=now/3 , b+=now/3 , c+=now/3;
		if(now%3 == 2) ++a , ++b;
		else if(now%3) ++a;
	}
	cout << a << ' '<< b << ' ' << c << '\n';
}
signed main(){latina();}