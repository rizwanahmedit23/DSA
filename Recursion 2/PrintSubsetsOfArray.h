void printSubsetsOfArray(int input[], int size, int sI, int output[], int outputEI){
	if(sI == size){
		for(int i =0;i<=outputEI;i++){
            cout<< output[i]<< " " ;
        }
        cout<< endl;
        return;
    }
    printSubsetsOfArray(input, size, sI+1, output, outputEI);
    output[outputEI+1] = input[sI];
    printSubsetsOfArray(input, size, sI+1, output, outputEI+1);
    return;
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[size]; 
    printSubsetsOfArray(input, size, 0, output, -1);
    return;
}
