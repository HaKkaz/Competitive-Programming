#include<iostream>
#include<sstream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	string s, i;
	int sum, j, k, l;
	while (getline(cin,s)){
		sum = 0;
		stringstream ss(s);
		while (true){
			ss >> i;
			k = i.size();
			for (j = 0, l = 0; j < k; j++){
				if (i[j] >= '0'&&i[j] <= '9')
					l = l * 10 + (i[j] - '0');
				else
					break;
			}
			if (ss.fail())
				break;
			if (j == k)
				sum += l;
		}
		cout << sum << "\n";
	}
}