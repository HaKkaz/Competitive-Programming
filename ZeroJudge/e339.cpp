#include<iostream>
#define int long long
using namespace std;
int res = 0;
signed main(){
	int n ;cin >> n;
	for(int i=1 ; i<=n ; ++i){
		int x;
		cin >> x;
		res += x;
		cout << res << ' ';
	}
}