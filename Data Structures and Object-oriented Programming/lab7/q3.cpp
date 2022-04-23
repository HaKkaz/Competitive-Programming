#include <iostream>
#include <vector>
using namespace std;

/* Add whatever you want*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n ;
    vector<int> a(n/2) , b(n/2) , ans;
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    int topa = 0 , topb= 0 ;
    while(topa<n/2 || topb<n/2){
        if(topb==n/2 || (topa<n/2 && a[topa] < b[topb])){
            ans.emplace_back(a[topa++]);
        }
        else{
            ans.emplace_back(b[topb++]);
        }
    }
    for(int &x : ans) cout << x << ' ';    
    return 0;
}