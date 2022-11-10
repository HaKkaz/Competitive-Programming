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
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
 	string str;
 	while(cin >> str){
 		int ch[26];
 		fill( ch , ch+26 , 0 );
 		for(int i=0 ; i<(int)str.size() ; i++){
 			if(str[i]>='a' && str[i]<='z'){
 				++ch[str[i]-'a'];
 			}
 			else if(str[i]>='A' && str[i]<='Z'){
 				++ch[str[i]-'A'];
 			}
 			else continue;
 		}
 		bool output=false,ok=false;
 		for(int i=0 ; i<25 ; i++){
 			if(ch[i]%2 && !ok ) ok=true;
 			else if(ch[i]%2 && ok ) {output=true; break;} 
 		}
 		if(output) cout << "no..." <<'\n';
 		else cout << "yes !" <<'\n';
 	}
}