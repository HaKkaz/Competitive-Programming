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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 	int T;
 	while(cin >> T){
 	 	vector<int> num;
 	 	for(int i=0 ; i<T ; i++){
 	 		int x; cin >> x;
 	 		num.push_back(x);
 	 	}   
 	 	sort( num.begin(),num.end() );
 	 	
 	 	for(int i=0 ; i<T ; i++){
 	 		cout << num[i];
 	 		if(i != T-1) cout << ' ';
 	 	}
 	 	cout << '\n';
 	 	if(num[0] >= 60) cout << "best case" <<'\n'<<num[0]<<'\n';
 	
 	 	else if(num[T-1] <60 ) cout << num[T-1] <<'\n'<< "worst case"<<'\n';
 	
 	 	else{
 	 	 	for(int i=0 ; i<T ; i++){
 	 	 		if(num[i+1]>=60 && num[i]<60) {
 	 	 			cout<<num[i]<<'\n';
 	 	 			cout<<num[i+1];
 	 	 			break;
 	 	 		}
 	 	 	}
 	 	 	cout<<'\n';
 	 	}
 	 }
}