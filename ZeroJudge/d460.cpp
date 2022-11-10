#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main( int argc, char** argv ) 
{

long long int a;

while (cin >> a)
{ 
if(0<=a&&a<6)
cout << 0 << endl ;
else if(5<a&&a<12)
cout << 590 << endl ;
else if(11<a&&a<18) 
cout << 790 << endl ;
else if(17<a&&a<60)
cout << 890 << endl ;
else if(a>=60)
cout << 399 << endl ;
} 

return 0;

}