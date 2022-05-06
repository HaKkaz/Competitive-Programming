#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
signed main(){
	IOS;
	int n; cin >> n ;
	vector<pii> v(n);
	map<int,int> MX,MN;
	for(auto &[x,y] : v){
		cin >> x >> y;
		MX[y] = -1;
		MN[y] = 2e9;
	}
	string s; cin >> s;
	string ans = "No";
	for(int i=0 ; i<n ; ++i){
		auto [x,y] = v[i];
		if(MX[y] > x and s[i] == 'R') ans = "Yes";
		if(MN[y] < x and s[i] == 'L') ans = "Yes";
		if(s[i] == 'L') MX[y] = max(MX[y] , x);
		if(s[i] == 'R') MN[y] = min(MN[y] , x);
	}
	cout << ans << '\n';
}