#include<bits/stdc++.h>	
#pragma GCC optimize ("Ofast")
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
#define rep(a , b , c) for(int c = a , c < b , ++c)
using namespace std;
map<string , int> mp;
int main(){//__IO
	int T;
	cin >> T >> ws;
	string s;
	while(T--){
		int n = 0;
		string str;
		while(getline(cin , str)){
			if(str == "") break;
			++n;
			++mp[str];
		}
		for(auto &c : mp){
			cout << fixed << setprecision(4) <<  c.F << ' ' <<(double)c.S/(double)n*100 << '\n';
		}
		cout << '\n';
		mp.clear();
	}
}