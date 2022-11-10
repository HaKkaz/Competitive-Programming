#include<bits/stdc++.h>
#define test_
#define PB push_back
#define S second
#define F first
#define all(x) (x).begin(),(x).end()
#define Size(x) (int)(x).size()
#define __IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define pii pair<int,int>
#define endl cout<<'\n';
const long long llMAX=2e18+20020522;
const unsigned long long ullMAX=1e19+20020522;
const int imax = 2e9+20020522;
using namespace std;
int main(){__IO
	int T; cin >> T;
	while(T--){
		string str;
		cin >> str;
		char c;
		int a = 0 , b = 0 , ok = 1;
		for(int i=0 ; i<Size(str) ; ++i){
			if(str[i]>='0' && str[i]<='9'){
				if(ok) a = a*10 + (str[i]-'0');
				else b = b*10 + (str[i]-'0');
			}
			else if(str[i]=='+') c='+' , ok = 0;
			else if(str[i]=='-') c='-' , ok = 0;
			else if(str[i]=='*') c='*' , ok = 0;
			else if(str[i]=='/') c='/' , ok = 0;
			else if(str[i]=='%') c='%' , ok = 0;
		}
		if(c=='+') cout << a + b <<'\n';
		else if(c=='-') cout << a-b <<'\n';
		else if(c=='*') cout << a*b <<'\n';
		else if(c=='/') cout << a/b <<'\n';
		else if(c=='%') cout << a%b <<'\n';
	}
}