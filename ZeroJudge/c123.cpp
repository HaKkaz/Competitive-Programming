#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(cin >> n){
		if(n == 0) return 0;
		while(1){
			string ans = "Yes\n";
			deque<int> want;
			for(int i=0 ; i<n ; ++i){
				int x; cin >> x;
				if(x == 0) 
					goto next_testcase;
				want.push_back(x);
			}
			int top = 1;
			stack<int> mid;
			while(want.size()){
				if(mid.size() && mid.top() == want.front()) want.pop_front() , mid.pop();
				else if(top <= want.front()) mid.push(top) , top++;
				else{
					ans = "No\n";
					break;
				}
			}
			cout << ans ;
		}
next_testcase:
		cout << '\n';
	}
}