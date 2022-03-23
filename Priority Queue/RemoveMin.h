#include <vector>

class PriorityQueue {
    vector<int> pq;
	void swap(int i,int j){
		int temp = pq[i];
        pq[j] = pq[i];
        pq[i] = temp;
    }
   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin(){
		if(pq.size() == 0){
            return -1;
        }
        int top = pq[0];
        int lastIndex = pq.size() - 1;
        
        int temp = pq[0];
        pq[0] = pq[lastIndex];
        pq[lastIndex] = temp;

        pq.pop_back();

        // Down Heapify
        int parentIndex = 0;
        int leftChildIndex;
        int rightChildIndex;
        int minIndex = parentIndex;
        while(parentIndex < pq.size() - 1){
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;            
            if(leftChildIndex >= pq.size()){
                break;
            }
            minIndex = leftChildIndex;
            if(rightChildIndex <= pq.size() - 1){
                if(pq[leftChildIndex] > pq[rightChildIndex]){
                        minIndex = rightChildIndex;
                }
            }
            if(pq[parentIndex] < pq[minIndex]){
                break;
            }
            int temp = pq[minIndex] ;
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            
            parentIndex = minIndex;
        }
        return top;
    }
};