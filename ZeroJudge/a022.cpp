#include<bits/stdc++.h>
using namespace std;
int main(){
	string a , b;
	while(cin >> a){
		b = a;
		reverse( a.begin() , a.end() );
		a == b ? cout<<"yes"<<'\n' : cout<<"no"<<'\n';
	}
}