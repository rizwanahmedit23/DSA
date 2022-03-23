#include<algorithm>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
	vector<int> ans;
    int n = input.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<input[i]->size();j++){
            ans.push_back(input[i]->at(j));
        }
    }
    sort(ans.begin(), ans.end());
    
    return ans;
}