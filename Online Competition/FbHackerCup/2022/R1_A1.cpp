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

bool solve(){
	int n , k;
	cin >> n >> k ;
	vector<int> a(n) , b(n);
	map<int,int> pos;
	for(int i=0 ; i<n ; ++i) cin >> a[i];
	for(int i=0 ; i<n ; ++i) cin >> b[i] , pos[b[i]] = i;

	if(k == 0 || k == 1) return (k == 1) ^ (a == b);
	else if(n == 2){
		return (k & 1)^(a == b);
	}
	else{
		for(int i=0,j=pos[a[0]] ; i<n ; ++i , j=(j+1)%n){
			if(a[i] != b[j]) return false;
		}
		return true;
	}

}

signed main(){
	fast;
	int t=1;
	cin >> t;
	for(int kase=1 ; kase<=t ; ++kase){
		// solve();
		cout << "Case #" << kase << ": " << (solve() ? "YES" : "NO") << '\n';
	}
}