#include<bits/stdc++.h>
using namespace std;
void move(int n,char x,char y){
	cout <<"Move ring "<<n<<" from " <<x<<" to "<<y<<'\n';
}
void solve(int n,char A,char B,char C){
	if(n == 1){ 
		move( n , A , C );
		return;
	}
	solve(n-1 ,A , C , B );
	move(n,A,C);
	solve(n-1 ,B , A , C );
}
int main(){
	int n; 
	while(cin>>n){
		solve(n,'A','B','C');
	}
}