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
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int a , b;
	while(cin >> a >> b){
		int k=(a*2+b)%3;
		if(k == 0) cout << "普通\n" ;
		else if(k == 1) cout << "吉\n" ;
		else cout<< "大吉\n" ;
	}
}