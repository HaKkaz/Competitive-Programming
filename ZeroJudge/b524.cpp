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
set<int> y,e;
signed main(){
	IOS;
	int n;
	string str;
	while(cin >> str){
		int now = 0 , ans = 0;
		for(int i=0 ; i<sz(str) ; ++i){
			if(str[i] == 'y'){
				ans += abs(i-now);
				now += 3;
			}
		}
		cout << ans << '\n';
	}
}