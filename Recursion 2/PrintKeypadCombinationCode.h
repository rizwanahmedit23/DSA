#include <iostream>
#include <string>
using namespace std;
string getKeypad(int num){
    if(num == 2){
        return "abc";
    }
    if(num == 3){
		return "def";
    }
    if(num == 4){
		return "ghi";
    }if(num == 5){
		return "jkl";
    }if(num == 6){
		return "mno";
    }if(num == 7){
		return "pqrs";
    }if(num == 8){
		return "tuv";
    }if(num == 9){
		return "wxyz";
    }
}
void printKeypad(int num, string output){
    if(num == 1 || num == 0){
		cout << output << endl;
        return;
    }
    string keypad=getKeypad(num%10);
    if(keypad.length()<4){
	    printKeypad(num/10, keypad[0] + output);
        printKeypad(num/10, keypad[1] + output);
        printKeypad(num/10, keypad[2] + output);
    }
    else{
        printKeypad(num/10, keypad[0] + output);
        printKeypad(num/10, keypad[1] + output);
        printKeypad(num/10, keypad[2] + output);
        printKeypad(num/10, keypad[3] + output);
    }
    return;
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
	printKeypad(num, output);  
}
