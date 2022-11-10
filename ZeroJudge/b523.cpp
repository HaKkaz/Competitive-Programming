#include<bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false),cin.tie(0);
	string str;
	set<string> s;
	while(getline(cin,str)){
		int a = s.size();
		s.insert(str);
		int b = s.size();
		if(a==b) puts("YES");
		else puts("NO");
	}
}