#include <iostream>
#include <string>
using namespace std;
void help(string input, string output){
    if(input.size() == 1){
		output += input[0];
        cout << output <<endl;
        return;
    }
    for(int i =0; i<input.size();i++){
        help(input.substr(0,i)+input.substr(i+1), output + input[i]);
    }
    return;
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	help(input, "");
}
