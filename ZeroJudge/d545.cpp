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
#define pss pair<string , string>
bool cmp(const pss &a , const pss &b){
	if(a.S != b.S){
		if(a.S.size() > b.S.size()) return 1;
		if(a.S.size() < b.S.size()) return 0;
		return a.S > b.S;
	}
	if(a.F == "S" || b.F == "S") return a.F=="S";
	if(a.F == "H" || b.F == "H") return a.F=="H";
	if(a.F == "D" || b.F == "D") return a.F=="D";
}
vector<pss> v;
signed main(){
	IOS;
	int n;
	cin >> n ;
	for(int i=0 ; i<n ; ++i){
		string a,b; cin >> a >> b;
		v.push_back({a,b});
	}
	sort(all(v),cmp);
	int m; cin >> m;
	cout << v[m-1].F << ' ' << v[m-1].S << '\n';
}