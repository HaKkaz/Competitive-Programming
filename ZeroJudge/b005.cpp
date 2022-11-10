#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3","unroll-loops")
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl cout<<'\n';
using namespace std;
int b[101][101];
int main(){
	int n; 
st:
	while(cin >> n){
		int ct1 = 0 , ct2 = 0 , pos1 = -1 , pos2 = -1;
		for(int i=0 ; i<n ; ++i)
			for(int j=0 ; j<n ; ++j)
				cin >> b[i][j];	
		for(int i=0 ; i<n ; ++i){
			int s1 = 0 , s2 = 0;
			for(int j=0 ; j<n ; ++j){
				s1 += b[i][j];
				s2 += b[j][i];
			}
			if(s1 % 2) pos1 = i , ++ct1;
			if(ct1 > 1) {cout << "Corrupt\n"; goto st;}
			if(s2 % 2) pos2 = i , ++ct2;
			if(ct2 > 1) {cout << "Corrupt\n"; goto st;}
		}
		if(pos1 == -1 && pos1 == -1){
			cout << "OK\n";
		}
		else if(pos1 != -1 && pos2 != -1){
			printf("Change bit (%d,%d)\n" , pos1+1 , pos2+1);
		}
		else if(pos1 == -1){
			printf("Change bit (%d,%d)\n" , pos1+1 , 0);
		}
		else{
			printf("Change bit (%d,%d)\n" , 0 , pos2+1	);
		}
	}
}