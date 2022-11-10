#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
bool cmp(string a , string b){
	if((a[0]=='-' || b[0]=='-')&&a[0]!=b[0]){
		if(a[0]=='-') return true;
		else return false;
	}
	else if(a[0]==b[0]&&a[0]=='-'){
		if(a.size()!=b.size()) return a.size()>b.size();
		else return a>b;
	}
	else{
		if(a.size()!=b.size()) return a.size()<b.size();
		return a<b;
	}
}
int main(){	
	int N;
	while(cin >> N){
		vector<string> num;
		for(int i=0 ; i<N ; ++i){
			string str;
			cin >> str;
			num.push_back(str);
		}
		sort(num.begin(), num.end() , cmp);
		for(auto &c:num) cout<<c<<'\n';
	}
}