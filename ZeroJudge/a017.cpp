#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
stack<string> op;
string input,tr;
queue<string> res;
int prior(string ch){
	if(ch=="+" || ch=="-") return 1;
	else if(ch=="*" || ch=="/" || ch=="%") return 2;
	else return 0;
}

bool is_op(string ch){
	if(ch=="+" || ch=="-" || ch=="*" || ch=="/" || ch=="%")
		return true;
	return false;
}

void to_post(string s){
	stringstream ss;
	ss<<input;
	while(!res.empty()) res.pop();
	while(ss>>tr){
		if(is_op(tr)){
			while(!op.empty() && prior(tr) <= prior(op.top())){
				res.push(op.top());
				op.pop();
			}
			op.push(tr);
		}
		else if(tr == "("){
			op.push(tr);
		}
		else if(tr == ")"){
			while(op.top()!="("){
				res.push(op.top());
				op.pop();
			}
			op.pop();
		}
		else{
			res.push(tr);
		}
	}
	while(!op.empty()){
		res.push(op.top());
		op.pop();
	}
}

int string_to_num(string s){
	int ret = 0;
	for(int i=0 ; i<s.size() ; i++){
		ret*=10;
		ret+=s[i]-'0';
	}
	return ret;
}

int main(){
	while(getline(cin,input)){
		to_post(input);
		stack<int> nums;
		while(!res.empty()){
			if(is_op(res.front())){
				int b = nums.top();
				nums.pop();
				int a = nums.top();
				nums.pop();
				
				if(res.front() == "+"){
					nums.push(a+b);
				}
				else if(res.front() == "-"){
					nums.push(a-b);
				}
				else if(res.front() == "*"){
					nums.push(a*b);
				}
				else if(res.front() == "/"){
					nums.push(a/b);
				}
				else{
					nums.push(a%b);
				}
				res.pop();
			}
			else{
				nums.push(string_to_num(res.front()));
				res.pop();
			}
		}
		cout<<nums.top()<<'\n';
		nums.pop();
	}
	return 0;
}