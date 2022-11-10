#include<iostream>
using namespace std;
signed main(){
	int n; cin >> n ;
	int f[45];
	f[1] = 1  , f[2] = 3;
	for(int i=3 ; i<=n ; ++i) f[i] = f[i-1] + f[i-2];
	cout << f[n] << '\n';
}