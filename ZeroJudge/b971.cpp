#include<bits/stdc++.h>
using namespace std;
main(){
	int a , b , c;
	cin >> a >> b >> c;
	if(a <= b)
		for(int i=a ; i<=b ; i+=c) cout << i << ' ';
	else
		for(int i=a ; i>=b ; i+=c) cout << i << ' ';
}