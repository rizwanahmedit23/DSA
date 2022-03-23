#include <string>
using namespace std;
void help(string input, string output){
	if(input.length() == 0){
        cout << output << endl;
        return;
    }
    if(input.length() == 1){
		int num = input[0] - '0';
        char numChar = num + 'a' - 1;
        cout << output + numChar << endl;
        return;
    }
    int firstNum = input[0] - '0';
    char firstChar = 'a' + firstNum - 1;
    help(input.substr(1), output + firstChar);
    if(input.length() >= 1){
    	int secondNum = input[1] - '0';
        int num = 10*firstNum + secondNum;
        char secondChar = num + 'a' - 1;
        if(num <=26)
        	help(input.substr(2), output + secondChar);
    }
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
	help(input, "");
}

