#include<bits/stdc++.h>
using namespace std;
bool isnum(string s){
	if(s[0]>='0'&&s[0]<='9') return 1;
	else if(s.size()>1 && s[1]>='0'&&s[1]<='9') return 1;
	return 0;
}
main(){ios::sync_with_stdio(false),cin.tie(0);
	string str;
	stringstream ss;
	stack<int> stk;
	while(getline(cin , str)){
			ss.clear();
			string now;
			ss << str;
		while(1){
			ss >> now;
			if(ss.fail()) break;
			if(isnum(now)){
				int num = stoi(now);
				stk.push(num);
			}
			else{
				int b = stk.top(); stk.pop();
				int a = stk.top(); stk.pop();
				
				if(now == "+"){
					stk.push(a+b);
				}
				if(now == "-"){
					stk.push(a-b);
				}
				if(now == "*"){
					stk.push(a*b);
				}
				if(now == "/"){
					if(a==0 || b==0) stk.push(0);
					else stk.push(a/b);
				}
				if(now == "%"){
					stk.push(a%b);
				}
			}
		}
		cout << stk.top() <<'\n';
	}
}