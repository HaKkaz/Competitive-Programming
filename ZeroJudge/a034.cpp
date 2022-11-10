#include<iostream>
#include<bitset>
using namespace std;
int main(){
	int n ; 
	while(cin >> n){
		const int X=n;
		bitset<10000> b(X);
		string str=b.to_string();
		bool flag = false;
		for(int i=0 ; i<str.size(); ++i){
			if(str[i]=='1') flag=true;
			if(flag) cout<<str[i];
		}
		cout<<'\n';
	}
}