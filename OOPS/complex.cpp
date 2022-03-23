#include <iostream>
using namespace std;

class ComplexNumbers {
    // Complete this class
    int real;
	int imag;
    public:
    
    ComplexNumbers(int r, int i){
        this->real = r;
        imag = i;
    }
    
    void plus(const ComplexNumbers c1){
        real += c1.real;
        imag += c1.imag;
    }
    void multiply(const ComplexNumbers c1){
        int temp = real;
        real *= c1.real;
        real += imag*c1.imag*-1;
        
        imag *= c1.real;
        imag += c1.imag*temp;
    }
    void print(){
        cout<<real<<" + i"<<imag;
    }
    
};
int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}