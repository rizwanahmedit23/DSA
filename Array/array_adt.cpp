#include<iostream>
using namespace std;
template <class T>
class array_adt{
    public:
        T element;
        T* a;
        int i, size;
        array_adt();
        void displaysize();
        void displayelement(int);
        int checkindex(int);
        void insert(int);
        void deletion(int);
        void options();
    };
template <class T>
array_adt<T> :: array_adt(){
    cout<<"enter array size"<<endl;
    cin>>size;
    a=new T[size];
    cout<<"enter array elements"<<endl;
    for(i=0;i<size;i++)
    cin>>*(a+i);
    }
template <class T>
void array_adt<T> :: displaysize(){
    cout<<"size of array is"<<size<<endl;
    }
template <class T>
void array_adt<T> :: displayelement(int n){
    cout<<"enter index to display element there"<<endl;
    cin>>n;
    checkindex(n);
    cout<<"element at index"<<n<<"is"<<*(a+n)<<endl;
    }
template <class T>
int array_adt<T> :: checkindex(int n){
    if(n<0||n>size){
        cout<<"index is invalid. try again"<<endl;
        exit(0);
        }
    else
        return 1;
    }   
template <class T>
void array_adt<T>::insert(int n){
    cout<<"enter element and index to insert it"<<endl;
    cin>>element>>n;
    if(checkindex(n)!=0){
        cout<<"array size will be increased to"<<size+1<<endl;
        size++;
        for(i=size;i>=n;i--){
            a[i]=a[i-1];
            a[n]=element;
            cout<<"new array is" <<endl;
            }
        for(i=0;i<size;i++)
            cout<<a[i]<<endl;
        }
    else
        cout<<"invalid index";
    }
template <class T>
void array_adt<T> :: deletion(int n){
    cout<<"enter index to delete element there";
    cin>>n;
    if(checkindex(n)!=0){
        cout<<"array size will be reduced to "<<size-1<<endl;
        size--;
        for(i=n;i<size;i++)
        a[i]=a[1+i];
        cout<<"new array is"<<endl;
        for(i=0;i<size;i++)
        cout<<a[i]<<endl;
        }
    else
       cout<<"invalid index"<<endl;
    }
template <class T>
void array_adt<T>:: options(){
    void displaysize();
    void displayelement(int);
    int checkindex(int);
    void insert(int);
    void deletion(int);
    }
int main(){
    int ch;
    cout<<"enter choice"<<endl;
    cout<<"1.int"<<endl<<"2.float"<<endl<<"3.char"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
{
array_adt<int> a1;
a1.options();
break;
}
case 2:
{
array_adt<float> a2;
a2.options();
break;
}
case 3:
{
array_adt<char> a3;
a3.options();
break;
}
}
}