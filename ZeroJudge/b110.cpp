#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
vector<string> c;
string ans="";
void sol(int y1 , int y2 , int x1 , int x2){
	char x = c[x1][y1];
	bool tag = 1;
	for(int i=x1 ; i<=x2 ; ++i){
		for(int j=y1 ; j<=y2 ; ++j){
			if(c[i][j] != x) tag=0;
		}
	}
	if(tag){
		if(x == '1') ans += "b ";
		else ans += "w ";
		return;
	} 
	else{
		ans += "g ";
		int xm=(x1+x2)>>1 , ym=(y1+y2)>>1;
		sol(ym+1 , y2 , x1 , xm);
		sol(y1 , ym , x1 , xm);
		sol(y1 , ym , xm+1 , x2);
		sol(ym+1 , y2 , xm+1 , x2);
	}
}
inline void solve(){
	IOS;
	int n;
	while(cin >> n){
		ans="" , c.clear();
		c.resize(n);
		for(int i=0 ; i<n ; ++i){
			cin >> c[i];
		}
		sol(0 , n-1 , 0 , n-1);
		if(ans[ans.size()-1]==' ') ans.pop_back();
		cout << ans << '\n';
	}
}
signed main(){solve();}