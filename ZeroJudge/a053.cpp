#include<bits/stdc++.h>
#define ED end()
#define BG begin()
#define PB push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define Size(x) (int)x.size()
#define BtoE(X) (X).begin(),(X).end()
#define test_
using namespace std;
int main(){
    int n;
    while(cin >> n){
    	int sum = 0;
    	if(n>=40){
    		cout << 100 <<'\n';
    		continue;
    	}
    	if(n>20){
    		sum += (n-20);
    		n = 20;
    	}
    	if(n>10){
    		sum += (n-10)*2;
    		n = 10;
    	}
    	sum += n*6;
    	cout << sum <<'\n';
    }
}