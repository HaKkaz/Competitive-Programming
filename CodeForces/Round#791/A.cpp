#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

signed main(){
	fast;
	int t=1;
	cin >> t;
	while(t--){
		int n ; cin >> n;
		if(n <= 3 || n%2 != 0) cout << -1 << '\n';
		else{
			if(n % 6 == 0) cout << n/6 ;
			else if(n/2 % 3 == 0) cout << n/2/3 ;
			else if(n/2 % 3 == 1) cout << (n/2-3)/3 + 2 ;
			else if(n/2 % 3 == 2) cout << (n/2)/3 + 1 ;

			cout << ' ';

			if(n % 4 == 0) cout << n/4;
			else cout << 1 + (n/2-3)/2 ;
			cout << '\n';
		}
	}
}