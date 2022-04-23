#include <iostream>

using namespace std;

class Complex{
public:
    Complex(){}
    Complex(float real, float image){
        //TO DO
        this->real = real;
        this->image = image;
        // write();
    }
    const Complex operator+(const Complex& k){
        // TO DO
        float _real = real + k.real;
        float _image = image + k.image;
        return Complex(_real , _image);
    }
    const Complex operator*(const Complex& k){
        // TO DO
        float _real = real * k.real - image * k.image;
        float _image = image * k.real + real * k.image;
        return Complex(_real , _image);
    }
    float getReal() const{
        // TO DO
        return real;
    }
    float getImage() const{
        // TO DO
        return image;
    }
private:
    float real,image;
};

ostream& operator<<(ostream& out,const Complex& k){
    float real, image;
    real = k.getReal();
    image = k.getImage();
    if(image >= 0)out<<real<<" + "<<image<<"i";
    else out<<real<<" - "<<-image<<"i";
    return out;
}

int main(){
    float real1, image1;
    float real2, image2;
    while(cin >> real1 >> image1 >> real2 >> image2){
        Complex myComplex1(real1, image1);
        Complex myComplex2(real2, image2);
        cout<< myComplex1 + myComplex2 << endl;
        cout<< myComplex1 * myComplex2 << endl;
      
    }
    return 0;
}