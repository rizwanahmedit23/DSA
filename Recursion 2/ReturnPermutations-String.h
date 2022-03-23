#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input.size() == 1){
        output[0] = input[0];
        return 1;
    }
    int size,length=0;
    string o1[10000];
    for(int i =0; i<input.size(); i++){
		size= returnPermutations(input.substr(0,i)+input.substr(i+1),o1);
        for(int j = 0; j < size; j++){
            output[length] = input[i] + o1[j];
            length++;
        }
    }
    return length;
}
