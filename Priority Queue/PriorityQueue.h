#include<vector>
class PriorityQueue{
    vector<int> pq;

    public:
    PriorityQueue(){

    }
    void insert(int val){
        pq.push_back(val);
        int childIndex = pq.size()-1;
        while(childIndex!=0){
            int parentIndex = (childIndex - 1) / 2;
            if(pq[parentIndex] < pq[childIndex] ){
                return;
            }
            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex] = pq[childIndex];
            childIndex = parentIndex;
        }
        return;
    }    

    int removeMin(){
        if(pq.size() == 0){
            return -1;
        }
        int top = pq[0];
        int lastIndex = pq.size() - 1;
        
        pq[0] = pq[lastIndex];
        pq.pop_back();

        // Down Heapify
        int parentIndex = 0;
        
        while(parentIndex < pq.size() - 1){
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int minIndex = parentIndex;
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