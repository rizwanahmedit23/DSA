#include<queue>
int buyTicket(int *arr, int n, int k) {
    // Brute Force approach Use a Priority Queue.
    priority_queue<int> maxPQ;
    for(int i=0;i<n;i++){
        maxPQ.push(arr[i]);
    }
    int time = 0, i = 0;
    while(i<n){
        if(arr[i] == maxPQ.top()){
            time++;
            maxPQ.pop();
            if(i==k)	return time;
        	i++;
        }
        else{
            int temp = arr[i];
            for(int j=i+1;j<n;j++){
				arr[j-1]=arr[j];
            }
            arr[n-1] = temp;
            if(i==k)	k=n-1;
            else	k--;
        }
    }
    return time;
}
// Optimal approach Use a Queue with Priority Queue.
// push indexes in the queue, instead of elements
// now it is very simple, just do as mentioned in the question.
