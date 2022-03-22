template <typename T>

class QueueUsingArray {
	T* data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

	public :
	QueueUsingArray() {
		data = new T[5];
        firstIndex=-1;
        nextIndex=0;
        size=0;
        capacity=5;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		if(size==0) return true;
        return false;
	}

	// insert element
	void enqueue(T element) {
        if(size==capacity){
            T*newData=new T[2*capacity];
            int j=0;
            for(int i=firstIndex;i<capacity;i++){
                newData[j]=data[i];
                j++;
            }
            for(int i=0;i<firstIndex;i++){
                newData[j]=data[i];
                j++;
            }
            firstIndex=0;
            nextIndex=size;
            capacity*=2;
            delete [] data;
            data=newData;
        } 
		data[nextIndex]=element;
        nextIndex=(nextIndex+1)%capacity;
        if(size==0) firstIndex++;
        size++;
	}
	
	T front() {
		if(size==0) return 0;
        return data[firstIndex];
	}

    void dequeue(){
        if(size==0) return;
        firstIndex=(firstIndex+1)%5;
        size--;

        if(size==0){
            firstIndex=-1;
            nextIndex=0;
        }
    }






























































};
