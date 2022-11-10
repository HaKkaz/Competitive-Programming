#include<iostream>
#include<cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	while(cin >> n){
		if(n == 0) break;
		int t = sqrt(n);
		(t*t == n) ? cout<<"yes"<<'\n' : cout<<"no"<<'\n';
	}
}