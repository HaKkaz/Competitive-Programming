#include <iostream>
#include <vector>
using namespace std;

/* Add whatever you want*/
int main() {
    int n; cin >> n ;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    
    int ans = 0 ;
    for(int i=0 ; i<n ; ++i){
        int MN = 2e9;
        int pos = 0;
        for(int j=i ; j<n ; ++j){
            if(arr[j] < MN){
                MN = arr[j];
                pos = j;
            }
        }
        if(pos != i) swap(arr[pos] , arr[i]) , ++ans;
    }
    cout << ans << '\n';
    return 0;
}