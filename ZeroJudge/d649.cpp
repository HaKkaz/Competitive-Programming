#include<bits/stdc++.h>
using namespace std;
main(){
	int n; 
	while(cin >> n&&n)
		for(int i=1 ; i<=n ; ++i){
			int a = n-i;
			for(int j=1 ; j<=a ; ++j) cout << '_';
			for(int j=1 ; j<=i ; ++j) cout << '+';
				cout << '\n';
		}
}