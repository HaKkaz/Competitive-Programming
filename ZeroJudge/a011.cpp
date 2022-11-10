#include<bits/stdc++.h>
using namespace std;
bool check(char x){
	return (x>='a'&&x<='z')||(x>='A'&&x<='Z')?1:0;
}
int main(){
	string str;
	while(getline(cin , str)){
		long long n = str.size() , ans = 0;
		for(int i=0 ; i<n-1 ; ++i){
			if((check(str[i])) && !(check(str[i+1]))) ++ans;
		}
		if(!check(str[n-2]) && check(str[n-1])) ++ans;
		cout << ans <<'\n';
	}
}