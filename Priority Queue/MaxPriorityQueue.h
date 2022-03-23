#include<vector>
#include<climits>
class PriorityQueue {
    // Declare the data members here
	vector<int> pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
        
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
		pq.push_back(element);
        int childIndex = pq.size() - 1;
        
        while(childIndex != 0){
			int parentIndex = (childIndex - 1)/2;
            if(pq[parentIndex] < pq[childIndex]){
				int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else {
                return ;
            }
            childIndex = parentIndex;
        }
        return;
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty())	return INT_MIN;
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(pq.size() == 0)	return INT_MIN;
        int top = pq[0];
        
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        
        int parentIndex = 0;
        while(parentIndex <= pq.size()-1){
			int leftChildIndex = 2 * parentIndex + 1;
			int rightChildIndex = 2 * parentIndex + 2;        	
        	if(leftChildIndex >= pq.size()){
        		return top;    
        	}
            int maxChildIndex = leftChildIndex;
            if(rightChildIndex <= pq.size()-1){
				if(pq[rightChildIndex] > pq[leftChildIndex]){
					maxChildIndex = rightChildIndex;
                }
            }
            
            if(pq[parentIndex] > pq[maxChildIndex])	return top;
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[maxChildIndex];
            pq[maxChildIndex] = temp;
            
            parentIndex = maxChildIndex;
        } 
        return top;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
    	if(pq.size() == 0)	return true;
        return false;
    }
};