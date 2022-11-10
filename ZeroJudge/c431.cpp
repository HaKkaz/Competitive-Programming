#include<stdio.h>
using namespace std;
int A[101];
main(){
	int n ;
	scanf("%d" , &n);
	for(int i=0 ; i<n ; ++i){
		int x;
		scanf("%d",&x);
		A[x]++;
	}
	for(int i=1 ; i<=100 ; ++i){
		while(A[i]) printf("%d ",i), A[i]--;
	}
}