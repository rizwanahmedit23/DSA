template <typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next; 
    
    MapNode(string key, V value){
        this -> key = key;
        this -> value = value;
        this -> next = NULL;
    }
    ~MapNode(){
        delete next;
    }
};
template <typename V>
class ourmap{
   MapNode<V>** bucket; 
   int count;
   int numBuckets;
    public:
        ourmap(){
            bucket = new MapNode<V>*[5];
            for(int i=0;i<5;i++){
                bucket[i] = NULL;
            }
            numBuckets = 5;
            count = 0;
        }
        int size(){
            return count;
        }
    private:
        int getbucketIndex (string key){
            int hashcode = 0;
            int currcoeff = 1;
            for(int i=key.size()-1; i>=0; i--){
                hashcode += key[i]*currcoeff;
                hashcode%=numBuckets;
                currcoeff*=37;
                currcoeff%=numBuckets;
            }
            hashcode%=numBuckets;
            return hashcode;
        }
    void rehash(){
        MapNode<V>** temp = bucket;
        bucket = new MapNode<V>*[2*numBuckets];
        int oldNumBuckets = numBuckets;
        numBuckets *= 2;
        for(int i=0;i<numBuckets;i++){
            bucket[i] = NULL;
        }
        count = 0;
        for(int i=0;i<oldNumBuckets;i++){
            MapNode<V>* head = temp[i];
            while(head != NULL){
                insert(head->key, head->value);
                head = head->next;
            }
            head = temp[i];
            delete head;
        }
        delete [] temp;
        cout << "rehashing done successfully"<<endl;
    }
    public:
        void insert(string key, V value){
            int bucketIndex = getbucketIndex(key);
            MapNode<V>* head = bucket[bucketIndex];
            while(head!=NULL){
                if(head->key == key){
                    head->value = value;
                    return;
                }
                head = head->next;
            }
            MapNode<V>* newNode = new MapNode<V>(key, value);
            head = bucket[bucketIndex];
            newNode->next = head;
            bucket[bucketIndex] = newNode;
            count ++;
            double loadFactor = (1.0*count) / numBuckets;
            if(loadFactor > 0.7){
                rehash();
            }
        }
    V remove(string key){
        int bucketIndex = getbucketIndex(key);
        MapNode<V>* head = bucket[bucketIndex];
        MapNode<V>* prev = NULL;
        while(head != NULL){
            if(head -> key == key){
                if(prev == NULL){
                    bucket[bucketIndex] = head->next;
                } 
                else{
                    prev->next = head->next;
                }
                head->next == NULL;
                V ans = head-> value;
                delete head;
                // Important: next-line
                count--;
                return  ans;
            }
            prev = head;
            head = head -> next;
        }
        return 0;
    }    
    V getValue(string key){
        int bucketIndex = getbucketIndex(key);
        MapNode<V>* head = bucket[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return head -> value;
            }
            head = head -> next;
        }
        cout<< "Key not present"<<" ";
        return 0;
    }
};