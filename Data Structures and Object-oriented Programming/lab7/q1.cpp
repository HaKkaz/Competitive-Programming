#include <iostream>
#include <vector>
using namespace std;

/* Add whatever you want*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n ;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    
    int ans = 0 ;
    for(int i=0 ; i<n ; ++i){
        for(int j=i+1 ; j<n ; ++j){
            if(arr[i] > arr[j]){
                swap(arr[i] , arr[j]);
                ++ans;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}