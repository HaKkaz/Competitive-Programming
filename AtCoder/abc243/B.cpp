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
	int n; cin >> n;
	int ans0 = 0 , ans1 = 0 ;
	vector<int> a(n) , b(n);
	for(int &X : a) cin >> X;
	for(int &X : b) cin >> X;
	for(int i=0 ; i<n ; ++i) ans0 += (a[i] == b[i]);

	set<int> st;
	for(int i=0 ; i<n ; ++i) st.insert(a[i]);
	for(int i=0 ; i<n ; ++i) ans1 += st.find(b[i]) != st.end();
	cout << ans0 << '\n' << ans1 - ans0 << '\n';
}