#include<stdio.h>
unsigned long long C[1005][1005];
int main(){
	C[0][0] = 1;
	for(int i=1 ; i<200 ; ++i){
		for(int j=0 ; j<=i ; ++j){
			if(j-1 >= 0) C[i][j] = (C[i-1][j-1] + C[i-1][j]);
			else C[i][j] = C[i-1][j];
		}
	}
	int n,m; 
	while(scanf("%d %d",&n,&m)){
		if(n == 0 && m == 0) break;
		printf("%d things taken %d at a time is %llu exactly.\n" , n , m , C[n][m]);
	}
}