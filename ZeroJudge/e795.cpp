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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int N = n;
		bool ok = true;
		while(N){
			int x = N;
			for(int i=2 ; i*i <= x ; ++i)
				if(x % i == 0){
					ok = false;
				}
			string tmp = to_string(N);
			reverse(all(tmp));
			int num = stoi(tmp);
			num/=10;
			tmp = to_string(num);
			reverse(all(tmp));
			N = stoi(tmp);
		}
		cout << n << (ok ? " is a Prime Day! " : " isn't a Prime Day! ") << '\n';
	}
}