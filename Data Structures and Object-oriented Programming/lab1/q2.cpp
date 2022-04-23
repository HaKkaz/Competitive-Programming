#include <iostream>
using namespace std;
int zero;
class calculator
{
    public: 
      int &a,&b,&c;
      calculator(int &_a):a(_a) , b(zero) , c(zero){}
      calculator(int &_a , int &_b):a(_a) , b(_b) , c(zero){}
      calculator(int &_a , int &_b , int &_c):a(_a),b(_b),c(_c){}
      int add(){
        return a + b + c;
      }
      void print(){
        cout << a << ' ' << b << ' ' << c << endl;
      }
};
 
int main()
{
    int a, b, c, d, e, f;
  
    calculator c1(a);
    calculator c2(b, c);
    calculator c3(d, e, f);
  
    cin >> a >> b >> c >> d >> e >> f ; 
    cout << c1.add() * c2.add() - c3.add() << endl;
    return 0;
}