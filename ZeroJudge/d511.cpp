#include<bits/stdc++.h>
using namespace std;
int a , b , c , ans;
int main(){
	for(int i=0 ; i<5 ; ++i){
		cin >> a >> b >> c ;
		if((a+b>c) && (a+c>b) && (b+c>a)) ++ans;
	}
	cout << ans;
}