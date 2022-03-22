#include<iostream>
using namespace std;

template <typename T>
class arrayAdt{
    T *a;
    int size;
    public:
        arrayAdt(){
            cout << "Enter the size of the array:"<<endl;
            cin >> size;

            cout << "Enter array elements:"<<endl;
            a=new T [size];
            for(int i=0;i<size;i++){
                cin>> *(a+i);
            }
        }
        void displayArray(){
            cout << "Elements in the array are:"<<endl;
            for (int i=0;i<size;i++){
                cout << a[i]<<endl;
            }
        }
        void displaySize(){
            cout << size <<endl;
        }
        bool checkIndex(int index){
            if (index>=size){
             return false;   
            }
            return true;
        }
        void insert(){
            int index,data;
            cout<<"Enter index and data to be inserted"<<endl;
            cin>>index>>data;
            bool check ;
            check=checkIndex(index);
            if (check || index==size){
                size++;
                int i;
                for(i=size-1;i>index;i--){
                    a[i]=a[i-1];
                }
                a[i]=data;
                cout<< "Data inserted succesfully"<<endl;
                return;
            }
            cout << "Invalid index";
            return;
        }
        void deletion(){
            int index;
            cout<<"Enter index to delete"<<endl;
            cin>>index;
            bool check;
            int temp;
            check=checkIndex(index);
            if(check){
                temp=a[index];
                for(int i=index+1;i<size;i++){
                    a[i-1]=a[i];
                    size--;
                }
            cout << "Item deleted successfully->"<<temp<<endl;
            }
        }
        void options(){
            while(1){
                int choice;
                cout << "enter choice"<<endl;
                cout<< "1.displaysize 2.checkindex 3.insertion ";
                cout<< "4.deletion 5.display array elements"<<endl;
                cin>>choice;
                switch (choice){
                    case 1:{
                        displaySize();
                        break;
                    }
                    case 2:{
                        int index;
                        cout<<"Enter index to be searched"<<endl;
                        cin>>index; 
                        checkIndex(index);
                        break;
                    }
                    case 3:{
                        insert();
                    break;
                    }
                    case 4:{
                        deletion();
                        break;
                    }
                    case 5:{
                        displayArray();
                        break;
                    }
                    default:
                        cout<<"invalid choice, enter again."<<endl; 
                }
            }
        }
};
int main(){
    int choice;
    cout<< "Enter choice"<<endl;
    cout<<"1.integer 2.float 3.char"<<endl;
    cin>>choice;
    switch (choice){
        case 1:{
            arrayAdt<int>a;
            a.options();
            break;
        }               
        case 2:{
            arrayAdt<float>a;
            a.options();
            break;
        }
        case 3:{
            arrayAdt<char>a;
            a.options();
            break;
        }
    }
}
