#include<bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false),cin.tie(0);
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		long long ans = 0;
		vector<char> stk;
		long long n = s.size();
		for(int i=0 ; i<n ; ++i){
			if(s[i] == 'p') stk.push_back('p');
			if(s[i] == 'q' && stk.size()) stk.pop_back() , ++ans;
		}
		cout << ans <<'\n';
	}
}