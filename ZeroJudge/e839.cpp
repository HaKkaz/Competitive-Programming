#include<bits/stdc++.h>
using namespace std;

map<string , vector<string> > clf;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n; cin >> n; 
	for(int i=0 ; i<n ; ++i){
		string a,b; cin >> a >> b;
		clf[b].push_back(a);
	}

	string which; cin >> which;

	if(clf[which].size() == 0){
		cout << "No" << endl;
	}
	else{
		sort(clf[which].begin() , clf[which].end());
		for(int i=0 ; i<clf[which].size() ; ++i){
			cout << clf[which][i] << endl;
		}
	}
}
