#include<bits/stdc++.h>
using namespace std;
map<char , int> mp;
string s = "mjqhofawcpnsexdkvgtzblryui";
int main(){
	int T;cin >> T;
	string str="uzrmatifxopnhwvbslekycqjgd";
	for(int i=1 ; i<=str.size() ; ++i){
		mp.insert({str[i-1] , i});
	}
	while(T--){
		int x; cin >> x;
		string f ; cin >> f;
		if(f[0] >= 'a' && f[0] <= 'z'){
			long long sum = 0;
			sum += mp[f[0]];
			for(int i=1 ; i<x ; ++i){
				cin >> f;
				sum += mp[f[0]];
			}
			cout << sum << '\n';
		}
		else{
			int now = 0;
			for(int i=0 ; i<f.size() ; ++i) now = now*10 + (f[i]-'0');
			cout << s[now-1];
			for(int i=1 ; i<x ; ++i){
				now = 0;
				cin >> f;
				for(int i=0 ; i<f.size() ; ++i) now = now*10 + (f[i]-'0');
				cout << s[now-1];
			}
			cout << '\n';
		}
	}
}