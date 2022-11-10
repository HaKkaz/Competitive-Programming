#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	string str; cin >> str;
	string ans="";
	char now = str[0];
	int cnt=1;
	for(int i=1 ; i<str.size() ; ++i){
		if(str[i]!=now){
			ans += to_string(cnt) , ans += now , now = str[i] , cnt = 1;
		}
		else cnt++;
	}
	ans += to_string(cnt) , ans += now;
	if(ans.size()<str.size()) cout<<ans<<'\n';
	else cout<<str<<'\n';
}