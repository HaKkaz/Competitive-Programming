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
    int n , m;
    while(cin >> n >> m){
        int sum=0;
        for(int i=0 ; ; i++){
            if(sum > m){
                if(i ==  0) cout << 1 <<'\n';
                else cout << i <<'\n';
                break;
            }
            sum += n+i;
        }
    }
}