#include<iostream>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n  , k; 
	while(cin >> n >> k){
		vector<int> v;
		int sum = 0;
		v.push_back(0);
		for(int i=0 ; i<n ; ++i){
			int x;  
			cin >> x;
			sum += x , v.push_back(sum);
		}
		for(int i=0 ; i<k ; ++i){
			int l , r ; cin >> l >> r; 
			cout << v[r]-v[l-1] <<'\n';
		}
	}
}