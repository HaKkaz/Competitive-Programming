#include<bits/stdc++.h>
#define test_
#define PB push_back
#define MP make_pair
#define Size size()
#define ED end()
#define BG begin()
#define St first
#define Nd second
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define pii pair<int,int>
using namespace std;

void init();
stack<int> stk , stk2;
long long ans;
int n;

vector<int> b;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
		
	while(cin >> n){
		init();
		//input
		for(int i=0 ; i<n ; i++){
			int x; cin >> x; 
			b.push_back(x);
		}
		//solve
		stk.push(b[0]);
		stk2.push(1);
		for(int i=1 ; i<n ; i++){
			while(stk.size() && b[i] > stk.top()){
				ans += stk2.top(), stk2.pop() ,stk.pop();
			}
		
			if(stk.size() && stk.top() == b[i]){
				ans += stk2.top();
				stk2.top()++;
			}
			else{
				stk.push(b[i]);
				stk2.push(1);
			}
			if(stk.size() > 1) ans++;
		}
		cout << ans*2 <<'\n';
	}
}
void init(){
	b.clear();
	while(stk.size()) stk.pop();
	while(stk2.size()) stk2.pop();
	ans = 0;
}