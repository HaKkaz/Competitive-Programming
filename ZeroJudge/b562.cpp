#include<bits/stdc++.h>
#define sz(x) (x).size()
using namespace std;
int p[20] , now = 1;
main(){ios::sync_with_stdio(false),cin.tie(0);
	string str;
	for(int i=0 ; i<=16 ; ++i) p[i] = now , now *= -2;
	while(cin >> str){
		int cur = 0 , ans = 0;
		for(int i=sz(str)-1 ; i>=0 ; --i , ++cur) ans += p[cur]*(str[i]-'0');
		cout << ans << '\n';
	}
}