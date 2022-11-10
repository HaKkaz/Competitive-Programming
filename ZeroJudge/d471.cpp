#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		string str="" , final="";
		for(int i=0 ; i<n ; ++i) final+='1',str+='0';
		cout<<str<<'\n';
		while(str!=final){
			if(str[n-1]=='0') str[n-1] = '1';
			else str[n-1] = '2';
			for(int i=n-1 ; i>=0 ; --i){
				if(str[i] == '2'){
					str[i] = '0';
					if(str[i-1]=='0') str[i-1] = '1';
					else str[i-1] = '2';
				}
			}
			cout<<str<<'\n';
		}
	}
}