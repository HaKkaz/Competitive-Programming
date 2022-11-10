#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(X) (X).begin(),(X).end()
#define Sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
#define __IO ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
const int mod = 1e9+7;
int main(){
	int T;
	cin >> T >> ws;
	while(T--){
		char c;
		long long Ow = 0 , O = 0;
		long long ans = 0;
		while((c = getchar()) != '\n'){
			if(c == 'O'){
				++O;
				O %= mod;
				ans += Ow;
				ans %= mod;
			}
			if(c == 'w'){
				Ow += O;
				Ow %= mod;
			}
		}
		cout << ans%mod << '\n';
	}
}