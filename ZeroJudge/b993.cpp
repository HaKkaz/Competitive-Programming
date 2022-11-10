#include<iostream>
using namespace std;
int main(){
int n ;  
    while(cin >> n){
        int mx = 0;
        int x;
        for(int i=0 ; i<n ; ++i){
        	cin >> x;
            if(x > mx) mx = x; 
        }
        cout << mx << '\n';
    }
}