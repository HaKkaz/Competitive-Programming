#include<bits/stdc++.h>
#define test_
#define pb push_back
#define S second
#define F first
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define et cout<<'\n';
#define rep(i , n) for(int mm=i ; mm<n ; ++mm)
using namespace std;
int main(){
__IO
	priority_queue<pii> pq;
	int n; cin >> n;
	for(int i=0 ; i<n ; ++i){
		int a , b;
		cin >> a >> b;
		pq.push({b , a});
	}
	int mx = 0 , now = 0;
	while(pq.size()){
		now += pq.top().S;
		mx = max(mx , pq.top().F + now);
		pq.pop();
	}
	cout << mx << '\n';
}