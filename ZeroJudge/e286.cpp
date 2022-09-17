#include<iostream>
using namespace std;
int main()
{
	int A , B , a[4] , b[4] , cnt = 0; 
	int tot = 0;
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	A = a[0]+a[1]+a[2]+a[3];
	cout << A << ":";
	cin >> b[0] >> b[1] >> b[2] >> b[3];
	B = b[0]+b[1]+b[2]+b[3];
	cout << B << '\n';
	if(A > B) ++cnt;
	//copy//
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	A = a[0]+a[1]+a[2]+a[3];
	cout << A << ":";
	cin >> b[0] >> b[1] >> b[2] >> b[3];
	B = b[0]+b[1]+b[2]+b[3];
	cout << B << '\n';
	if(A > B) ++cnt;
	//
	if(cnt == 2) cout << "Win\n";
	else if(cnt == 1) cout << "Tie\n";
	else cout << "Lose\n";
}