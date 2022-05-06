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
	int n,x; cin >> n >> x;
	string s; cin >> s;
	vector<char> stk;
	int now = x;
	while(now > 1){
		int b = now & 1;
		now >>= 1;
		if(b) stk.emplace_back('R');
		else stk.emplace_back('L');
	}
	reverse(all(stk));
	for(char &dir : s){
		if(dir == 'U'){
			stk.pop_back();
		}
		else{
			stk.push_back(dir);
		}
	}
	x=1;
	for(char &dir : stk){
		if(dir == 'L') x = x << 1;
		if(dir == 'R') x = x << 1 | 1;
	}
	cout << x << '\n';
}