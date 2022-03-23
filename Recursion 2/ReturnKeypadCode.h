#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 1 || num == 0){
		output [0] = "";
        return 1;
    }
    int smallOutput = keypad(num/10, output);
    int a = num%10;
    switch (a){
        case 2: 
            for(int i = 0; i<smallOutput; i++){
                output[i+smallOutput] =output [i]+'b';
                output[i+2*smallOutput] =output [i]+'c';
				output[i] =output [i]+'a';
            }
            smallOutput *= 3;
        break;
        case 3:
            for(int i = 0; i<smallOutput; i++){
                output[i+smallOutput] = output [i]+'e';
                output[i+2*smallOutput] =output [i] +'f';
                output[i] = output [i]+'d';
            }
            smallOutput *= 3;
        
        break;
    	 case 4:
            for(int i = 0; i<smallOutput; i++){
                output[i+smallOutput] =output [i]+'h';
                output[i+2*smallOutput] =output [i]+ 'i';
                output[i] =output [i]+'g';
            }
            smallOutput *= 3;
        
        break;
    	case 5:
            for(int i = 0; i<smallOutput; i++){
                output[i+smallOutput] =output [i]+'k';
                output[i+2*smallOutput] =output [i] +'l';
				output[i] =output [i]+'j';          
            }      
            smallOutput *= 3;
        
        break;
        case 6:
            for(int i = 0; i<smallOutput; i++){
                output[i+smallOutput] =output [i]+'n';
                output[i+2*smallOutput] =output [i] +'o';
				output[i] =output [i]+'m';
            }
            smallOutput *= 3;
        
        break;
        case 7:
            for(int i = 0; i<smallOutput; i++){
                output[i+smallOutput] = output [i]+'q';
                output[i+2*smallOutput] =output [i] +'r';
                output[i+3*smallOutput] =output [i] +'s';
				output[i] = output [i]+'p';
            }
            smallOutput *= 4;
        
        break;
        case 8:
            for(int i = 0; i<smallOutput; i++){
                output[i+smallOutput] = output [i]+'u';
                output[i+2*smallOutput] =output [i]+ 'v';
				output[i] = output [i]+'t';
            }
            smallOutput *= 3;
        
        break;
        case 9:
            for(int i = 0; i<smallOutput; i++){
                output[i+smallOutput] =output [i]+'x';
                output[i+2*smallOutput] =output [i] +'y';
                output[i+3*smallOutput] =output [i] +'z';
				output[i] =output [i]+'w';
            }
            smallOutput *= 4;
        
        break;
    }
    return smallOutput;
}
