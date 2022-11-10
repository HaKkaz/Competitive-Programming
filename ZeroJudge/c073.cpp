#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	node *nxt , *pre;
	int val;
	int bot;
}node;

node *arr[30];

int valid(int a , int b){
	if(a == b) return 0;

	node *A = arr[a];
	while(A != nullptr){
		if(A->val == b) return 0;
		A = A->nxt;
	}

	node *B = arr[b];
	while(B != nullptr){
		if(B->val == a) return 0;
		B = B->nxt;
	}

	return 1;
}

void reset(node *now){
	if(now->nxt != nullptr) reset(now->nxt);
	now->nxt = nullptr;
	now->pre = nullptr;
	now->bot = 1;
}

int main(){
	int n; 
	while(scanf("%d" , &n) != EOF){
		for(int i=0 ; i<n ; ++i){
			arr[i] = (node*)malloc(sizeof(node));
			arr[i]->nxt = nullptr;
			arr[i]->pre = nullptr;
			arr[i]->val = i;
			arr[i]->bot = 1;
		}
		while(1){
			char s1[10],s2[10];
			int a,b;
			scanf("%s",s1);
			if(s1[0] == 'q') break;
			scanf("%d %s %d" , &a , s2 , &b);

			if(!valid(a,b)) {
				// printf("invlaid : %d %d\n" , a , b);
				continue;
			}

			if(s1[0] == 'm'){
				if(s2[1] == 'n'){//move onto
					if(arr[a]->nxt) reset(arr[a]->nxt) , arr[a]->nxt = nullptr;
					if(arr[b]->nxt) reset(arr[b]->nxt) , arr[b]->nxt = nullptr;
					arr[b]->nxt = arr[a];
					arr[a]->pre = arr[b];
					arr[a]->bot = 0;
				}
				if(s2[1] == 'v'){//move over
					if(arr[a]->nxt) reset(arr[a]->nxt) , arr[a]->nxt = nullptr;
					node *now = arr[b];
					while(now->nxt != nullptr) now = now->nxt;
					now->nxt = arr[a];
					arr[a]->pre = now;
					arr[a]->bot = 0;
				}
			}
			if(s1[0] == 'p'){
				if(s2[1] == 'n'){//pile onto
					if(arr[b]->nxt) reset(arr[b]->nxt) , arr[b]->nxt = nullptr;
					arr[b]->nxt = arr[a];
					arr[a]->pre = arr[b];
					arr[a]->bot = 0;
				}
				if(s2[1] == 'v'){//pile over
					if(arr[a]->pre != nullptr) arr[a]->pre->nxt = nullptr;
					node *now = arr[b];
					while(now->nxt != nullptr) now = now->nxt;
					now->nxt = arr[a];
					arr[a]->pre = now;
					arr[a]->bot = 0;
				}
			}
			
		}
		for(int i=0 ; i<n ; ++i){
			printf("%d:",i);
			if(arr[i]->bot){
				node *now = arr[i];
				printf(" %d",now->val);
				while(now->nxt != nullptr){
					now = now->nxt;
					printf(" %d", now->val);
				}
			}
			puts("");
		}
	}
}