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
signed main(){
	IOS;
	int t=1;
	cin >> t;
	while(t--){
		string s; cin >> s;
		int ans = 0 , cnt = 0 ;
		for(int i=0 ; i<sz(s) ; ++i){
			if(s[i] == 'O') ++cnt , ans += cnt;
			else cnt = 0;
		}
		cout << ans << '\n';
	}
}