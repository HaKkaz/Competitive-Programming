#include<bits/stdc++.h>
using namespace std;
main(){
	int a , b;
	char c;
	while(cin >> a >> c >> b)
	if(c == '+') cout << a + b << '\n';
	else if(c == '-') cout << a - b << '\n';
	else if(c == '*') cout << a * b << '\n';
	else if(c == '/') cout << a / b << '\n';
}