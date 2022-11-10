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
const int mod = 1e9+7;
using namespace std;
const int maxn = 100001;
inline void latina(){
	loli;
	int a , b , c;
	while(cin >> a >> b >> c){
		if(a == max({a,b,c})){
			if(a > b+c) cout << "A\n";
			else if(b > c) cout << "B\n";
			else cout << "C\n";
		}
		if(b == max({a,b,c})){
			if(b > a+c) cout << "B\n";
			else if(a > c) cout << "A\n";
			else cout << "C\n";
		}
		if(c == max({a,b,c})){
			if(c > a+b) cout << "C\n";
			else if(b > a) cout << "B\n";
			else cout << "A\n";
		}
	}
}
signed main(){latina();}