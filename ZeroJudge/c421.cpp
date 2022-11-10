#include<bits/stdc++.h>
#define ED end()
#define BG begin()
#define PB push_back
#define MP make_pair
#define ll long long
#define pii pair<int,int>
#define Size(x) (int)x.size()
#define BtoE(X) (X).begin(),(X).end()
#define F first
#define S second
#define test_
using namespace std;
bool chk[5000005];
/*
bool cmp(pair<int,int> &p1,pair<int,int> &p2){
	return p1.first < p2.first;
}
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 	
 	priority_queue<pair<int,int>  , vector<pair<int,int> > , less<pair<int,int> > > pql;
 	priority_queue<pair<int,int>  , vector<pair<int,int> > , greater<pair<int,int> > > pqg;
 	int input , cnt = 0 ;
 	while(cin >> input && input){

 		if(input > 0){
 			++cnt;
 			pql.push({input,cnt});
 			pqg.push({input,cnt});
 		}
 		else if(input == -1 && pqg.size()>0 ){
 			while(pqg.size() && chk[pqg.top().S]) pqg.pop();
 			if(pqg.size()){
 			 	cout << pqg.top().F <<' ';
 			 	chk[pqg.top().S] = true;
 			 	pqg.pop();
 			}
 		}
 		else{
 			while(pql.size() && chk[pql.top().S]) pql.pop();
 			if(pql.size()){
 			 	cout << pql.top().F <<' ';
 			 	chk[pql.top().S] = true;
 			 	pql.pop();
 			}
 		}
 	}
 }