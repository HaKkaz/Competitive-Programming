#include"bits/stdc++.h"
#define sz(x) (int)(x).size()
#define loli ios::sync_with_stdio(false),cin.tie(0);
using namespace std;
int n;
char rt , need, r;
string str;
set<string> ans;
inline char getroot(string tmp){
	while(tmp.size()>1){
		int tot = 0;
		while(tmp.size()){
			tot += tmp.back()-'0' , tmp.pop_back();
		}
		tmp = to_string(tot);
	}
	return tmp[0];
}
inline void solve(int pos){
	string a="";
	for(int i=0 ; i<pos ; ++i) a += str[i];
	a += need;
	for(int i=pos ; i<sz(str) ; ++i) a += str[i];
	ans.insert(a);
}
inline void latina(){loli;
	cin >> n >> r >> str;
	const int N = n-1;
	rt = getroot(str);
	need =  char((r-'0'+9-rt+'0')%9+'0');

	for(int i=0 ; i<N ; ++i) solve(i);
	solve(N);
	if(need == '0')
	need = '9';

	for(int i=0 ; i<N ; ++i) solve(i);
	solve(N);
	ans.erase(ans.begin()) , ans.erase(--ans.end());
	for(auto &c : ans) cout << c << '\n';
}
signed main(){latina();}