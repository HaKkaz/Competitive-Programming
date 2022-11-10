#include<bits/stdc++.h>
using namespace std;
int n;
string x;
bool cmp(const string &a , const string &b){
	return a+b>b+a;
}
main(){ios::sync_with_stdio(false),cin.tie(0);
	vector<string> v;
	while(cin>>n){
		for(int i=0;i<n;++i)cin>>x,v.push_back(x);
		sort(v.begin(),v.end(),cmp);
		for(auto &c:v) cout<<c;
		cout<<'\n',v.clear();
	}
}