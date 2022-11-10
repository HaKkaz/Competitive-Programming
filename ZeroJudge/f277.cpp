#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
vector<pair<int , pair<int , pair<string , string> > > > v;
signed main(){
	IOS;
	int n; cin >> n ;
	while(n--){
		int a,b;
		string A,B;
		cin >> A >> a >> b >> B;
		v.push_back({a,{b,{A,B}}});
	}
	sort(all(v));
	for(auto &c : v){
		cout << c.F << ' ' << c.S.F << ' ' << c.S.S.F << '\n';
		cout << c.S.S.S << '\n';
	}
}