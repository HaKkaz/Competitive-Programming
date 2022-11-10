#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int main(){
	vector<pair<int,int>> v1,v2;
	int a, b;
   while(scanf("%d:%d",&a,&b)&&a&&b)
   	v1.push_back(make_pair(a,b));
   
   while(scanf("%d:%d",&a,&b)&&a&&b)
   	v2.push_back(make_pair(a,b));
   
   int i=0,j=0;
   long long ans = 0;
   #define all(x) (x).begin(),(x).end()
   sort(all(v1)),sort(all(v2));
   while(i<v1.size()&&j<v2.size()){
   	if(v1[i].first==v2[j].first)
   		ans+=v2[j].second*v1[i].second,++i,++j;
   	else if(v1[i].first<v2[j].first) ++i;
   	    
   	else  ++j;
   	    
   }
   cout<<ans;
}