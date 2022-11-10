#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define int long long
#define pb push_back
#define MP make_pair
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = "  << x << '\n';
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
signed main(){
	IOS;
	int t=1;
	string str;
	cin >> t >> ws;
	cout << "Lumberjacks:\n";
	while(t--){
		getline(cin , str);
		stringstream ss;
		ss << str;
		int x;
		vector<int> a;
		while(ss >> x) a.push_back(x);
		vector<int> b(a) , c(a);
		sort(all(b)) , sort(all(c));
		reverse(all(b));
		if(a == b || a == c) cout << "Ordered\n";
		else cout << "Unordered\n";
	}
}