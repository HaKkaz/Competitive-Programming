#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; 
	while(cin >> n){
		string str;
		map<string , int > mp;
		int cnt=0;
		for(int i=0 ; i<n ; i++){
			cin >> str;
			if(mp[str] > 0) {
				cout <<"Old! "<< mp[str] <<'\n';
			}
			else{
				mp[str] = ++cnt;
				cout <<"New! "<< mp[str] <<'\n';
			}
		}
	}
}