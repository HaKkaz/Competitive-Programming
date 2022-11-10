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
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int T; 
    cin >> T;
    int cnt=0; 
    while(T--){
     	int a,b;
     	cin >> a >> b;
     		int sum = 0;
     		for(int i=a ; i<=b ; i++){
     			int c = sqrt(i);
     			if(c*c == i) sum += i; 
     		}
     		cnt++;
     		cout  <<"Case "<< cnt <<": "<< sum <<'\n';
    }
}