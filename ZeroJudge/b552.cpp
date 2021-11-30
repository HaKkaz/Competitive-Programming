#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
signed main(){
	IOS;
	string x;
	while(cin >> x){
		vector<int> ans;
		int st = 0 ;
		for(int i=0 ; i<x.size() ; ++i){
			int xx = stoll(x.substr(st , i-st+1));
			bool is_prime = true;
			for(int j=2 ; j*j <= xx ; ++j){
				if(xx % j == 0) is_prime = false;
			}
			if(xx > 1 && is_prime) ans.push_back(xx) , st = i+1;
		}
		cout << ans.size() << '\n';
		for(int &xx : ans) cout << xx << '\n';
		cout << '\n';
	}
}