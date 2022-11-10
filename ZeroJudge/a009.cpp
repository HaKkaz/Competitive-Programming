#include<bits/stdc++.h>
using namespace std;
int main(){
		string str;
	while(cin>>str){
		for(int mi=0;mi<str.size();mi++){
			cout<<(char)(str[mi]-7);
		}
		cout<<'\n'; 
	}
}