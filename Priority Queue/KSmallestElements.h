#include<algorithm>
#include<queue>
vector<int> kSmallest(int arr[], int n, int k) {
    //	BRUTE FORCE APPROACH
/*    sort(arr, arr+n-1);
    vector<int> ans;
    for(int i=0;i<k;i++){
        ans.push_back(arr[i]);
    }
    return ans;
*/    
    //	OPTIMISED APPROACH
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
		pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
		if(arr[i]<pq.top()){
			pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int> ans;
    for(int i=0;i<k;i++){
    	int item = pq.top();
        pq.pop();
		ans.push_back(item);
    }
    return ans;
}