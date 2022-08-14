#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	string s; cin >> s;

	int n; cin >> n;
	//輸入 n 個字串，跟s最比對
	for(int i=0 ; i<n ; ++i){
		string t; cin >> t;

		//A
		int cnt_A = 0;
		for(int j=0 ; j<4 ; ++j){
			if(s[j] == t[j]){
				cnt_A++;
			}
		}

		//B
		int cnt_B = 0;
		for(int j=0 ; j<4 ; ++j){
			for(int k=0 ; k<4 ; ++k){
				if(s[j] == t[k] && j != k){
					cnt_B++;
				}
			}
		}
		cout << cnt_A << 'A' << cnt_B << 'B' << '\n';
	}
}