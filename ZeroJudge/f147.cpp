#pragma GCC optimize("Ofast", "unroll-loops", "fast-math")
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

array<map<int,pair<string,int>> , 2> dish{
	map<int,pair<string,int>>{
		{1,{"Medium Wac",4}},
		{2,{"WChicken Nugget",8}},
		{3,{"Geez Burger",7}},
		{4,{"ButtMilk Crispy Chicken",6}},
		{5,{"Plastic Toy",3}}
	},
	map<int,pair<string,int>>{
		{1,{"German Fries",2}},
		{2,{"Durian Slices",3}},
		{3,{"WcFurry",5}},
		{4,{"Chocolate Sunday",7}}
	}
};

int main(){
	fast;
	int total=0;
	int opt;
	while(cin >> opt){
		if(opt == 0) break;
		int id; cin >> id;
		--opt;
		cout << dish[opt][id].first << ' ' << dish[opt][id].second << '\n';
		total += dish[opt][id].second;
	}
	cout << "Total: " << total << '\n';
}