#include<iostream>
using namespace std;
long long aabs(long long x){
	return max(x , -x);
}
int main(){
	string s;
	cin >> s;
	long long a=0 , b=0;
	for(int i=0 ; i<s.size() ; i+=2){
		a += (s[i]-'0');
		if(i+1<s.size()) b += s[i+1]-'0';
	}

	cout << aabs(a-b) <<'\n';
}