#include<iostream>
using namespace std;
signed main(){
	int n;
	int sum = 0;
	cin >> n ;
	for(int i=1 ; i<=n ; i+=2) sum += i;
	cout << sum << '\n';
}