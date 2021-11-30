#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	string s[3],T;
 	for(int i=0 ; i<3 ; ++i) cin >> s[i];
 	cin >> T;
 	for(int i=0 ; i<T.size() ;  ++i){
 		cout << s[T[i]-'1'];
 	}
}