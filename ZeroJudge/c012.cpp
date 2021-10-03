#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
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
	string s; 
	while(getline(cin , s)){
		array<int,256> cnt;
		vector<pii> ans;
		cnt.fill(0);
		for(char &ch : s) cnt[ch]++;
		for(int i=0 ; i<256 ; ++i) if(cnt[i]) ans.push_back({cnt[i],-i});
		sort(all(ans));
		for(auto &c : ans) cout << -c.S << ' ' << c.F << '\n';
		cout << '\n';		
	}
}