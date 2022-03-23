#include<iostream>
using namespace std;

class DynamicdegCoeffay {
    int* data;
    int nextIndex;
    int capacity;

    public:
        DynamicdegCoeffay(){
            data = new int[5];
            nextIndex = 0;
            capacity = 5;
        }
        DynamicdegCoeffay(DynamicdegCoeffay const &d){
            this->data = new int[d.capacity];
            for(int i=0;i<d.nextIndex;i++){
                data[i]=d.data[i];
            }
            this->capacity = d.capacity;
            this->nextIndex = d.nextIndex;
        }
        void operator = (DynamicdegCoeffay const &d){
            this->data = new int[d.capacity];
            for(int i=0;i<d.nextIndex;i++){
                data[i]=d.data[i];
            }
            this->capacity = d.capacity;
            this->nextIndex = d.nextIndex;
        }
        void add(int element){
            if(nextIndex==capacity){
                int* newData = new int [capacity * 2];
                for(int i=0;i<capacity;i++){
                    newData[i]=data[i];
                }
                delete [] data;
                data=newData;
                capacity *= 2; 
            }
            data[nextIndex] = element;
            nextIndex++;
            return;
        }
        int get(int index) const{
            if(index < nextIndex){
                return data[index];
            }
            else 
                return -1;
        }
        void add(int i, int element){
            if(i<nextIndex){
                data[i] = element;
            }
            else if(i == nextIndex){
                add(element);
            }
            else
                return;
        }
        void print() const{
            for(int i=0;i<nextIndex;i++){
                cout<< data[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    DynamicdegCoeffay d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    

    DynamicdegCoeffay d2 = d1;
    d2.add(0, 70);
    d1.print();
    d2.print();

    DynamicdegCoeffay d3;
    d3 = d1;
    d3.print();
}
