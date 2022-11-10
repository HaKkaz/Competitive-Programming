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
    int T;
    cin >> T;
    while(T--){
        string n;
        cin >> n;
        int sum=n[0]-'0';
        for(int i=1 ;i<(int)n.size() ; i++)
            sum *= (n[i]-'0');
        cout << sum <<'\n';
    }
}