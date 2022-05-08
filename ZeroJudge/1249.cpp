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
	int n;
	while(cin >> n && n!=0){
		vector< pair<string , string> > name(n);
		for(int i=0 ; i<n ; ++i){
			string s; cin >> s;
			name[i].second = s;//original s
			sort(s.begin() , s.end());
			name[i].first = s;//sorted s
		}

		sort(name.begin() , name.end());

		vector< vector<string> > ans;
		vector< string > tmp;
		string last = "";
		for(int i=0 ; i<n ; ++i){
			if(name[i].first == last) {
				tmp.push_back(name[i].second);
			}
			else{
				if(tmp.size() > 1){
					ans.push_back(tmp);
				}
				tmp.clear();
				tmp.push_back(name[i].second);
			}
			last = name[i].first;
		}
		if(tmp.size()>1) ans.push_back(tmp);
		sort(ans.begin() , ans.end());

		for(auto &v : ans){
			for(int i=0 ; i<v.size() ; ++i){
				cout << v[i];
				if(i != v.size()-1) cout << ',';
			}
			cout << '\n';
		}
		if(ans.size() == 0) cout << "No Answer\n";
	}
}