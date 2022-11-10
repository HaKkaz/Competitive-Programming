#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
signed main(){
	int n ,G;
	while(cin >> n &&n){
		G=0;
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
		    G+=__gcd(i,j);
		}
		cout<<G<<'\n';
	}
}