#include<bits/stdc++.h>
using namespace std;



int main(){
	int x;
	unordered_map<int, int> mp;
	while(cin >>  x) mp[x]++;

		for(auto &c: mp)
			if(c.second % 3)
				return cout << c.first , 0;
}