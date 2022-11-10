#include<stdio.h>
#include<bitset>
using namespace std;
bitset<10000001> vis;
int main(){
    int n; scanf("%d",&n);
 	for(int i=0 ; i<n ; ++i){
 		int x;
 		scanf("%d",&x);
 		vis[x] = 1;
 	}
 	int cnt = 0;
 	for(int i=0 ; i<=10000000 ; ++i){
 		if(vis[i]){
			if(cnt == 0) printf("%d ",i);
 			++cnt;
 			if(cnt == 10) cnt = 0;
 		}
 	}
}