#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int num[105][105];
	while(cin >> n >> m){
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> num[i][j];
			}
		}
		for(int i=0 ; i<m ; i++){
			for(int j=0 ; j<n ; j++){
				cout << num[j][i] << ' ';
			}
			cout<<'\n';
		}
	}
}