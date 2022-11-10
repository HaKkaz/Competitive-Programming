#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define Size(x) (int)x.size()
#define all(X) (X).begin(),(X).end()
#define F first
#define S second
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int main(){
__IO
	priority_queue<int> pq;
	int n , mx , mn = 1e9 , now , x;
	cin >> n;
	for(int i=0 ; i<n ; i++){
		cin >> x;
		mn = min(mn , x) , pq.push(x);
	}
	now = mx = pq.top() , pq.pop();
	while(--now , pq.size()){
		if(pq.top() != now){
			cout << mn <<' '<< mx << " no\n";
			return 0;
		}
		pq.pop();
	}
	cout << mn <<' '<< mx <<" yes\n";
}