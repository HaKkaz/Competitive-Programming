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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n ;
    while(n--){
        long long  a,b,c;
        while(cin >> a >> b >> c){
        	if(a == 1){
        		cout<<b+c<<'\n';
        	}
        	else if(a == 2){
        		cout<<b-c<<'\n';
        	}
        	else if(a == 3){
        		cout<<b*c<<'\n';
        	}
        	else{
        		cout<<b/c<<'\n';
        	}
        }
    }
}