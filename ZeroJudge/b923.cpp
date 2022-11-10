#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    stack<int> s;
    for(int i=0 ; i<T ; i++){
        int n;
    	cin >> n;
    	if(n == 1){
    		if(!s.empty()) s.pop();
    	}
    	else if(n == 2){
    		cout << s.top() <<'\n';
    	}
    	else{
    		int m ; 
    		cin >> m;
    		s.push(m);
    	}
    }
}