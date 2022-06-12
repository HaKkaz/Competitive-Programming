#include <iostream>
using namespace std;

int main(){
	string s; cin >> s;
	int n = s.size();
	bool same = true;
	if(n%2==1){
		same = false;
	}
	for(int i=0 ; i<n/2 ; ++i){
		if(s[i] != s[n-i-1]){
			same = false;
		}
	}
	if(same){
		cout << "YES" << endl;
		for(int i=0 ; i<n/2 ; ++i){
			cout << s[i];
		}
	}
	else{
		cout << "NO" << endl;
	}
}