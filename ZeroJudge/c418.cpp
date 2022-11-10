#include<bits/stdc++.h>
using namespace std;
main(){
	int n; cin >> n ;
	for(int i=1 ; i<=n ; ++i){
		int T = i;
		while(T--) cout << '*';
		cout << '\n';
	}
}