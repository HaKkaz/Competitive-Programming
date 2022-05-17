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
	int t ; cin >> t;
	for(int i=0 ; i<t ; ++i){
		cout << "Case #" << i+1 << ": ";
		int n; cin >> n ;
		vector<int> a(n);
		for(int &x : a) cin >> x;
		sort(all(a));
		int top=0,ans=0;
		for(int i=1 ; i<=n ; ++i){
			while(top < n && a[top] < i) ++top;
			if(top < n && a[top] >= i) ++top , ++ans;
		}
		cout << ans << '\n';
	}
}