#include <iostream>
#include <cmath>
using namespace std;

//Class for a bank certificate of deposit:
class CDAccount
{
    public:
        //TODO
        CDAccount(double a, double b , int c){
            _balance = a;
            _interest_rate = b;
            _term = c;
        }

        double get_interest_earned();
    private:
        double _balance;
        double _interest_rate;
        int _term; //months until maturity
};

int main( )
{
    double balance, interest_rate;
    int term;

    cin >> balance >> interest_rate >> term;
    CDAccount acc(balance, interest_rate, term);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << acc.get_interest_earned() << endl;

    return 0;
}

double CDAccount::get_interest_earned(){
    //TODO
    return _balance * pow((1.0 + _interest_rate/100.),_term/12.) - _balance;
}