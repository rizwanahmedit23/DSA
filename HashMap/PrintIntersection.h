#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int, int> ourMap;
    for(int i=0;i<n;i++){
		ourMap[arr1[i]] ++;
      //pair<int,bool> p(arr[i], true);
      //ourMap.insert(p);
    }
    for(int i=0;i<m;i++){
		if(ourMap.count(arr2[i]) > 0){
            if(ourMap[arr2[i]]>0){
                cout<<arr2[i]<<endl;
        		ourMap[arr2[i]] --;
            }
        }
    }
}