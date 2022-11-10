#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	
	while(cin >> n){
		vector< pair<int ,int> > v;
		for(int i=0 ; i<n ; i++){
			int x,y;
			cin >> x >> y;
			v.push_back({x,y});
		}
		sort(v.begin(),v.end());
		for(auto &x:v) cout << x.first <<" "<< x.second <<'\n';
	}
	
}