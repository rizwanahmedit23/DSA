#include<iostream>

using namespace std;
#include "ourmap.h"
int main(){

    ourmap <int> map;
    for(int i=0;i<10;i++){
        string key = "abc";
        char c = i + '0';
        key = key + c;
        int value = i+1;
        map.insert(key, value);
        cout<< "inserted-" << key<<":"<<value<<endl; 
    }
    cout<< "size:"<<map.size()<<endl;;
    for(int i=0;i<10;i++){
        string key = "abc";
        char c = i + '0';
        key = key + c;
        cout<< key<<":"<<map.getValue(key) << endl;
    }
    cout<< "end of code";
}