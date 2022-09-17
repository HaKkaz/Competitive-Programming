#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define all(x) (x).begin(),(x).end()
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
signed main(){
	IOS;
	int n; cin >> n ;
	set<string> st;
	string s[n];
	for(int i=0 ; i<n ; ++i){
		cin >> s[i];
	}
	int ans=0;
	sort(s , s+n , [](const string &a ,const string &b){
		return a.size() < b.size();
	});
	for(int i=0 ; i<n ; ++i){
		for(int len=1 ; len<=100 ; len++){
			const int sz = s[i].size();
			if(len*2 < sz) continue;
			if(sz < len) continue;
			bool same = true;
			for(int l=0 , r=len ; r<sz ; ++l,++r){
				if(s[i][l] != s[i][r]){
					same = false;
					break;
				}
			}
			if(same){
				string wanna="";
				for(int j=sz ; j<(len<<1) ; ++j){
					wanna += s[i][j-len];
				}
				if(st.find(wanna) != st.end()){
					++ans;
				}
			}
		}
		st.insert(s[i]);
	}
	cout << ans << '\n';
}