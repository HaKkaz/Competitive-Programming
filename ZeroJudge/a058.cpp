#include<iostream>
using namespace std;
int main(){
	int num[3];
	int n;
	while(cin >> n){
		for(int j=0 ; j<3 ; j++) num[j]=0;
		for(int i=0 ; i<n ; i++){
			int x; cin >> x;
			x%=3;
			num[x]+=1;
		}
		for(int i=0 ; i<3 ; i++){
			cout << num[i] <<' ';
		}
	}
}