#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b ; cin >> a >> b;
	if(a>b) swap(a,b);
	if(a%2) ++a ;
	if(b%2) --b ;

	cout<<(b-a)/2+1<<'\n';
}