#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
signed main(){
	IOS;
	int n; cin >> n ;
	char ch;
	for(int i=0,j=0,k=0 ; k<n*n ; ++k,++j){
		cin >> ch;
		if(j == n) j=0 , ++i;
		if(i==j)
			cout << ch;
	}
}