#include<queue>
void findMedian(int *arr, int n)
{
    // BRUTE FORCE APPROACH
/*
    for(int i=0;i<n;i++){
        int j = i-1;
        while(j>=0 && arr[j+1] < arr[j]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
        if( (i+1) % 2 == 0){
            int ans = (arr[i/2]+arr[i/2 + 1]) / 2;
            cout<< ans << " ";
        }
        else{
            int ans = arr[i/2];
            cout<< ans<<" ";
        }
    }
*/

	//Optimised
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;    
    for(int i=0;i<n;i++){
        if(maxPQ.empty()){
            maxPQ.push(arr[i]);
            cout<< arr[i] << " ";
        }
        else if(maxPQ.size() < minPQ.size()){
            if(arr[i] <= minPQ.top()){
               maxPQ.push(arr[i]);
            }
			else{
                int top = minPQ.top();
                minPQ.pop();
                maxPQ.push(top);
                
                minPQ.push(arr[i]);
            }
			int ans = (minPQ.top() + maxPQ.top()) / 2;
			cout<< ans << " ";
        }
        else if(minPQ.size() < maxPQ.size()){
			if(arr[i] >= maxPQ.top()){
                minPQ.push(arr[i]);
            }
            else{
            	int top = maxPQ.top();
                maxPQ.pop();
                minPQ.push(top);
                
                maxPQ.push(arr[i]);
            }
            int ans = (minPQ.top() + maxPQ.top()) / 2;
			cout<< ans << " ";
        }
        else {
			if(arr[i] <= minPQ.top()){
                maxPQ.push(arr[i]);
                cout<< maxPQ.top() << " ";
            }
            else{
				minPQ.push(arr[i]);
                cout<< minPQ.top() << " ";
            }
        }
    }
}