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
int ans = 0 ;
string s;
int pos=-1;
void solve(int x1 , int x2 , int y1 , int y2){
	++pos;
	if(s[pos] == '1'){
		ans += (x2 - x1 + 1) * (y2 - y1 + 1);
		return;
	}
	if(s[pos] == '0'){
		return;
	}
	int midx = (x2 + x1)/2 , midy = (y1 + y2)/2;
	solve(x1 , midx , y1 , midy);
	solve(x1 , midx , midy+1 , y2);
	solve(midx+1 , x2 , y1 , midy);
	solve(midx+1 , x2 , midy+1 , y2);
}
signed main(){
	// IOS;
	int n;
	cin >> s >>	n;
	solve(1 , n , 1 , n);
	cout << ans << '\n';
}