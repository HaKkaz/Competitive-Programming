#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define LINE cout << "\n---------------\n";
#define endl cout << '\n';
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
signed main(){
	IOS;
	int t=1;
	cin >> t;
	while(t--){
		stack<char> stk;
		string s; cin >> s;
		bool ok = 1;
		for(int i=0 ; i<sz(s) ; ++i){
			if(s[i] == '(' || s[i] == '[' || s[i] == '<' || s[i] == '{') stk.push(s[i]);
			else if(stk.size()){
				if(s[i] ==  ')' and stk.top() == '(') stk.pop();
				else if(s[i] == ']' and stk.top() == '[') stk.pop();
				else if(s[i] == '>' and stk.top() == '<') stk.pop();
				else if(s[i] == '}' and stk.top() == '{') stk.pop();
				else{
					ok = 0;
					break;
				}
			}
			else{
				ok=0;
				break;
			}
		}
		if(stk.size()) ok = 0;	
		if(ok) cout << "Y\n";
		else cout << "N\n";
	}
}