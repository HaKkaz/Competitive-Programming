#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	int X; cin >> X;
 	if(X < 40) cout << 40-X << '\n';
 	else if(X < 70) cout << 70-X << '\n';   
 	else if(X < 90) cout << 90-X << '\n';
 	else cout << "expert\n";
}
