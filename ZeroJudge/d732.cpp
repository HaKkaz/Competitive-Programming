#include<bits/stdc++.h>
#define test_
#define PB push_back
#define S second
#define F first
#define all(x) (x).begin(),(x).end()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
typedef pair<int,int> pii;
int main(){
__IO
	int n ,q ,x;
	cin >> n>> q;
	vector<int> v;
	for(int i=0 ; i<n ;v.PB(x),++i) cin >> x;
	for(int i=0 ; i<q ; ++i){
		cin >> x;
		int id = lower_bound(all(v),x)-v.begin();
		if(v[id] == x) cout<<id+1<<'\n';
		else cout<<0<<'\n';
	}
}