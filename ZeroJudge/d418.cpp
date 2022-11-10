#include<iostream>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int T; 
	cin >> T;
	while(T--){
		int N; cin >> N;
		if(N==1){
			cout<<"1\n";
			continue;
		}
		vector<int> v;
		int now = 9;
		while(N>1 && now>1){
			if(!(N%now)) N/=now , v.push_back(now);
			else --now;
		}
		if(N==1 && v.size()) for(int i=v.size()-1 ; i>=0 ; i--) cout<<v[i];
		else cout<<-1;
		cout<<'\n';
	}
}