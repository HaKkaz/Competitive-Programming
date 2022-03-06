#include<bits/stdc++.h>
#define S second
#define F first
#define Sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
map<string , vector<string> > mp;
int main(){
__IO
	int n;
	while(cin >> n && n){
		mp.clear();
		bool flag = false;
		string x;
		for(int i=0 ; i<n ; ++i){
			cin >> x;
			string tmp = x;
			sort(all(tmp));
			mp[tmp].push_back(x);
		}

		for(auto &c : mp) if(Sz(c.S) > 1) flag = true;
		if(!flag) cout << "No Answer\n";
		vector<vector<string> > ans;
		for(auto &c : mp){
			if(c.S.size() > 1){
				sort(all(c.S));
				ans.push_back(c.S);
			}		
		}
		sort(all(ans));
		for(auto &c : ans){
			for(int i=0 ; i<Sz(c) ; ++i){
				cout << c[i];
				if(i + 1 < Sz(c)) cout << ',';
				else cout << '\n';
			}
		}
	}
}