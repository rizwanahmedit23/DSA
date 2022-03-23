#include<iostream>
using namespace std;

class Student{
    string name;

    string gender;
    public:
    int age;
    Student(){
        cout << "default constructor"<<endl;
    }

    Student(string n,int a,string g){
        name=n;
        age=a;
        gender=g;
    }
    void getDetails(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;
    }
    Student(Student& a){
        name=a.name;
        age=a.age;
        gender=a.gender;
    }
    ~Student(){
        cout<< "Destructor called"<<endl;
    }
    bool operator == (Student a){
        if (name==a.name && age==a.age && gender==a.gender ){
            return true;
        }
        return false ;
    }
};

int main(){
    string n,g;
    int a;
    cin>>n>>a>>g;

    Student s1(n,a,g);
    Student s2(s1);
    s2.age=19;
    s1.getDetails();
    s2.getDetails();
    if(s1==s2){
        cout << "same";
    }
    else {
        cout << "not same ";
    }
    return 0;
}