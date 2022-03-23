#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Polynomial{
    
    int capacity;

    public:
    int *degCoeff;
        Polynomial(){
            degCoeff = new int[5];
            for(int i=0;i<5;i++){
                degCoeff[i]=0;
            }
            capacity=5;
        };
        Polynomial(int capacity){
            degCoeff = new int[capacity];
            for(int i=0;i<capacity;i++){
                degCoeff[i]=0;
            }
            this->capacity = capacity;
        };
        Polynomial(Polynomial const &p2){
            this ->degCoeff = new int[p2.capacity];
            for(int i =0;i<p2.capacity;i++){
                this->degCoeff[i] = p2.degCoeff[i]; 
            }
            this->capacity = p2.capacity;
        }
        void setCoefficient(int degree, int coefficient){
            if(degree>=capacity){
                int newdegCoeffSize = degree+1;
                int *newdegCoeff = new int [degree+1];
                for(int i = 0;i<capacity;i++){
                    newdegCoeff[i] = degCoeff[i];
                }
                for(int i=capacity;i<=degree;i++){
                    newdegCoeff[i]=0;
                }
                delete [] degCoeff;
                degCoeff = newdegCoeff;
                capacity = degree+1;
            }
            degCoeff[degree] = coefficient;
        }
        Polynomial operator + (Polynomial const &p2){
            int pNewCapacity = max(capacity,p2.capacity);
            Polynomial pNew(pNewCapacity);
            int i=0;
            for(i=0;i<capacity&&i<p2.capacity;i++){
                pNew.degCoeff[i] = this->degCoeff[i]+p2.degCoeff[i];
            }
            while(i<(this->capacity)){
                pNew.degCoeff[i] = degCoeff[i];
                i++;
            }
            while(i<(p2.capacity)){
                pNew.degCoeff[i] = p2.degCoeff[i];
                i++;
            }
            return pNew;
        }
        Polynomial operator - (Polynomial const &p2){
            int pNewCapacity = max(capacity,p2.capacity);
            Polynomial pNew(pNewCapacity);
            int i=0;
            for(i=0;i<capacity&&i<p2.capacity;i++){
                pNew.degCoeff[i] = this->degCoeff[i]-p2.degCoeff[i];
            }
            while(i<(this->capacity)){
                pNew.degCoeff[i] = degCoeff[i];
                i++;
            }
            while(i<(p2.capacity)){
                pNew.degCoeff[i] = -(p2.degCoeff[i]);
                i++;
            }
            return pNew;
        }
        Polynomial operator *(Polynomial const &p2){
            Polynomial pNew(capacity+p2.capacity-1);
            for(int i=0;i<capacity;i++){
                for(int j=0;j<p2.capacity;j++){
                    pNew.degCoeff[i+j]+=degCoeff[i]*p2.degCoeff[j];
                }
            }
            return pNew;
        }
        void operator=(Polynomial const &p2){
            delete [] degCoeff;
            this ->degCoeff = new int[p2.capacity];
            for(int i =0;i<p2.capacity;i++){
                this->degCoeff[i] = p2.degCoeff[i]; 
            }
            this->capacity = p2.capacity;
        }
        
        void print(){
            for(int i = 0; i<capacity;i++){
                if(degCoeff[i]==0)
                    continue;
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }

};
int main()
{
    Polynomial p1;
    p1.degCoeff[0]=1;
    p1.degCoeff[1]=4;
    p1.degCoeff[3]=2;
    p1.degCoeff[5]=5;

    Polynomial p2;
    p2.degCoeff[0]=2;
    p2.degCoeff[1]=4;
    p2.degCoeff[2]=6;

    Polynomial p3 = p1+p2;
    p3.print();
    

}