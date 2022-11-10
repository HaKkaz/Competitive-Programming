#include<bits/stdc++.h>
using namespace std;
	string str[100005];
int main(){
	int n ; 
	cin >> n ;
	getline(cin,str[0]);
	for(int i=0 ; i<n ; ++i) getline(cin , str[i]);
	sort(str,str+n);
	for(int i=0 ; i<n ; ++i) cout << str[i]<<'\n';
}