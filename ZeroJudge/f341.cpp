#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
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
	string a,b;
	cin >> a >> b;
	const int n = b.size();
	for(int i=0 ; i+n-1 < sz(a) ; ++i){
		if(a.substr(i,n) == b){
			string x="",y="";
			for(int j=0 ; j<i ; ++j) x += a[j];
			for(int j=i+n ; j<sz(a) ; ++j) y+=a[j];
				reverse(all(x)) , reverse(all(y));
			cout << y << b << x << '\n';
			return 0;
		}
	}
}