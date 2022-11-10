#include<bits/stdc++.h>
using namespace std;
int n , m;

struct node{
	int val = 0;
	node *next = nullptr;
}*people[1100000];

void init(){
	people[1] = new node;
	people[1]->val = 1;
	for(int i=2 ; i<=n ; i++){
		people[i] = new node;
		people[i]->val = i;
		people[i-1]->next = people[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin >> n >> m){
		init();	
		for(int i=0 ; i<m ; i++){
			int kill; cin >> kill;
			if(people[kill]->next == nullptr || people[kill]->val  == 0){
				cout<<"0u0 ...... ?"<<'\n';	
			}
			else{
				cout<<(people[kill]->next)->val<<'\n';
				people[kill]->next->val = 0;
				people[kill]->next = people[kill]->next->next;
			}
			
		}
	}	
}