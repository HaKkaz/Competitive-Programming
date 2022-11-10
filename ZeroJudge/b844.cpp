#include<bits/stdc++.h> 
using namespace std; 
vector<int> num; 
int main(){ 	
    ios::sync_with_stdio(0); 	
    cin.tie(0); 	
    int n,q,T; 	
    while(cin >> n >> T){
    	num.clear();
	    for(int i=0;i<n;i++){ 		
			int x; 		
			cin>>x; 		
			num.push_back(x); 	
	    } 	//1 2 3 3 8
	    sort(num.begin(),num.end()); 	
	    while(T--){
	    	cin >> q;
	    	int l=0,r=n-1,mid;
	    	if(num[n-1]<=q){
				if(n%2) cout<<1<<'\n';
				else cout<<0<<'\n';continue;
			}
	    	while(l!=r){
	    		mid=(l+r)/2;
	    		if(num[mid]<=q){
	    			l=mid+1;
				}
				else{
					r=mid;
				}
			}
			if(l%2)	cout<<1<<'\n';
			else	cout<<0<<'\n';
		}
	}
	return 0;
}
/*
10 3
3 1 3 2 8 9 7 7 0 5
3 6 9
*/