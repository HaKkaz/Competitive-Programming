#include <iostream>
using namespace std;
/* Add whatever you want. */
#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define _ <<' '<<
#define ALL(v) v.begin(),v.end()
#define ft first
#define sd second
#define tiii tuple<int,int,int>
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

int main(){
	#define int long long
	fast;
	stack<int> stk;
	int q; cin >> q;
	while(q--){
		int opt ; cin >> opt;
		if(opt == 0){
			int x; cin >> x;
			stk.push(x);
		}
		if(opt == 1){
			stk.size() ? (stk.pop(),0) : (cout << "Not legal\n" , 0);
		}
		if(opt == 2){
			stk.size() ? (cout << stk.top() << '\n' , 0) : (cout << "Not legal\n" , 0) ;
		}
		if(opt == 3){
			cout << stk.size() << '\n';
		}
	}
	if(stk.size()){
		vector<int> v;
		while(stk.size()) v.emplace_back(stk.top()) , stk.pop();
		while(v.size()) cout << v.back() << " \n"[v.size() == 1] , v.pop_back();
	}
	else cout << "No data\n";
}
