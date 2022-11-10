#include<bits/stdc++.h>
#define int long long
using namespace std;
main(){
	int n ; 
	while(cin >> n && n){
		priority_queue<int,vector<int>,greater<int> > pq;
		for(int i=0 ; i<n ; i++){
			int x; cin >> x;
			pq.push(x);
		}
		int sum = 0;
		while(pq.size()>1){
			int a=pq.top();
			pq.pop();
			int b=pq.top();
			pq.pop();
			sum += (a+b);
			pq.push(a+b);
		}
		cout << sum <<'\n';
	}
}