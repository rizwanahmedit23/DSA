#include <unordered_map>
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> ourmap;
    int maxFreq=0, maxFreqNumber=-1;
    for(int i=0;i<n;i++){
        ourmap[arr[i]] ++;
    }
    for(int i=0;i<n;i++){
		if(ourmap[arr[i]] > maxFreq){
            maxFreq = ourmap[arr[i]];
            maxFreqNumber = arr[i];
        }
	}
    return maxFreqNumber;
}