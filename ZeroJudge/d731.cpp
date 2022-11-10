#include<iostream>
#include<algorithm>
#include<deque>
#define all(v) (v).begin(),(v).end()
using namespace std;
int main(){ios::sync_with_stdio(false),cin.tie(0);
	int T; cin  >> T;
	while(T--){
		deque<int> dq , dq2 ,ans;
		int n , x  , flag , ok=1; 
		cin >> n;
		//input
		for(int i=0 ; i<n ; ++i){
			cin >> x ;
			if(x > 0) dq.push_back(x);
			else dq2.push_back(x);
		}
		//sort
		sort(all(dq),greater<int>()) , sort(all(dq2),less<int>());
		//init c
		if(dq.empty() && dq2.empty()){
			cout<<0<<'\n';
			continue;
		}
		else if(dq.empty() || dq2.empty()){ 
			cout<<1<<'\n' ;
			continue;
		}
		else if(abs(dq.front()) > abs(dq2.front())) ans.push_back(dq.front()) , dq.pop_front() , flag = 0;
		else ans.push_back(dq2.front()) , dq2.pop_front() , flag = 1;
		//solve
		while(ok){
			if(flag){
				if(dq.empty()) {ok = 0; break;}
				else if(abs(dq.front()) < abs(ans.back())) ans.push_back(dq.front()) , dq.pop_front() , flag = 0;
				else dq.pop_front(); 
			}
			else{
				if(dq2.empty()) {ok = 0; break;}
				else if(abs(dq2.front()) < abs(ans.back())) ans.push_back(dq2.front()) , dq2.pop_front() , flag = 1;
				else dq2.pop_front();
			}
		}
		cout << ans.size() <<'\n';
	}
}