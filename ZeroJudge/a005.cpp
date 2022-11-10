#include<iostream>
using namespace std;
int main(){
	int N;
	while(cin>>N){
		while(N--){
			int num[4];
			for(int i=0 ; i<4 ; i++){
				cin>>num[i];
				cout<<num[i]<<' ';
			}
			if( (num[2]-num[1]) == (num[3]-num[2]) )
			{
				cout << num[3]+num[3]-num[2] <<'\n';
			}else{
				cout << num[3]*(num[2]/num[1]) << '\n';
			}
		}
	}
}