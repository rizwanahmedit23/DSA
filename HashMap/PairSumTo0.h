#include <unordered_map>
int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int, int> ourMap;
    int count = 0;
    for(int i=0;i<n;i++){
    	if(arr[i] >= 0)	ourMap[arr[i]] ++;
    }
    for(int i=0;i<n;i++){
        if(arr[i]<0){
			if(ourMap.count(0-arr[i]) > 0){
            		count= count+ ourMap[0-arr[i]];
			}
        }
	}
    if(ourMap.count(0) > 0){
    	int pairsOf0 = ( ourMap[0]*(ourMap[0] - 1) )/2;
    	count += pairsOf0;
    }
    return count;
}