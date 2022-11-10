#include"bits/stdc++.h"
#define pb push_back
#define mp make_pair
#define int long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define rz(x) resize(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define LINE cout<<"--------------------------\n";
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
int b[24] = {1<<0,1<<1,1<<2,1<<3,1<<4,1<<5,1<<6,
                1<<7,1<<8,1<<9,1<<10,1<<11,1<<0|1<<3,
                1<<1|1<<4,1<<2|1<<3,1<<3|1<<4,1<<4|1<<5,
                1<<3|1<<7,1<<4|1<<8,1<<6|1<<7,1<<7|1<<8,
                1<<8|1<<9,1<<7|1<<10,1<<8|1<<11};
int dp[1<<12];
inline void latina(){
	loli;
	dp[0] = 1;
	//for(int i=0 ; i<10 ; ++i) cout << dp[i] << ' ';
	for(int i=0 ; i<4096 ; ++i){
		for(int j=0 ; j<24 ; ++j){
			if((i&b[j]) == b[j]){
				dp[i] |= !dp[i-b[j]];
			}
		}
	}
	int t ; cin >> t;
	while(t--){
		int ans = 0;
		string str; cin >> str;
		for(int i=0 ; i<sz(str) ; ++i)
			ans |= ((str[i]-'0')<<i);
		cout << dp[ans];
	}
}
signed main(){latina();}