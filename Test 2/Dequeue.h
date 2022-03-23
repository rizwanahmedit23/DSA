/**********
 
 Following is the main function we are using internally.
 Refer this for completing the Dequeue class.
 
 
 int main()
 {
 Deque dq(10);
 int choice,input;
 while(true) {
 cin >> choice;
 switch (choice) {
 case 1:
 cin >> input;
 dq.insertfront(input);
 break;
 case 2:
 cin >> input;
 dq.insertrear(input);
 break;
 case 3:
 dq.deletefront();
 break;
 case 4:
 dq.deleterear();
 break;
 case 5:
 cout << dq.getFront() << "\n";
 break;
 case 6:
 cout << dq.getRear() << "\n";
 break;
 default:
 return 0;
 }
 }
 
 return 0;
 }
 
 ************/


class Deque {
    // Complete this class
    int *data;
    int front;
    int rear;
    int capacity;
    int size;
    
    public:
    Deque(int size){
        data = new int[size];
        front=-1;
        rear=-1;
        capacity=0;
        this->size=size;
    }
    void insertFront(int val){
        if(capacity==size){
            cout<<-1<<endl;
            return;
        }
		if(capacity==0){
			rear++;
		}
        front=(front+size-1)%size;
        data[front] = val;
        capacity++;
    	return ;
    }
    void insertRear(int val){
		if(capacity==size){
            cout<<-1<<endl;
            return;
        }
        if(capacity==0){
            front++;
        }
        rear=(rear+1)%5;
    	data[rear] = val;
    	capacity++;
        return;
    }
    void deleteFront(){
        if(capacity==0){
            cout<<-1<<endl;
            return;
        }
        capacity--;
        front=(front+1)%5;
        if(capacity==0){
        	front=-1;
            rear=-1;
        }
        return;
    }
    void deleteRear(){
        if(capacity==0){
            cout<<-1<<endl;
            return;
        }
        rear=(rear+size-1)%size;
        capacity--;
        if(capacity==0){
        	front=-1;
            rear=-1;
        }
        return;
    }
    int getFront(){
        if(capacity==0){
            return -1;
        }
        return data[front];
    }
    int getRear(){
        if(capacity==0){
            return -1;
        }
        return data[rear];
    }
};
// class Deque {
//     // Complete this class
//     int *data;
//     int front;
//     int rear;
//     int capacity;
//     int size;
    
//     public:
//     Deque(int size){
//         data = new int[size];
//         front=-1;
//         rear=-1;
//         capacity=0;
//         this->size=size;
//     }
    
    
//     bool isEmpty(){
//         return (front==-1);
//     }
//     void insertFront(int val){
//         if(capacity==size){
//             cout<<-1<<endl;
//             return;
//         }
// 		if(front==-1){
// 			front=0;
//             rear=0;
// 		}else{
//         front=((front-1)%size+size)%size;
        
        
//         }
//         capacity++;
//         data[front] = val;
//     }
//     void insertRear(int val){
// 		if(capacity==size){
//             cout<<-1<<endl;
//             return;
//         }
//         if(front==-1){
//             front=0;
//             rear=0;
//         }else{
//         rear=(rear+1)%size;
    	
    	
//         }
//         data[rear] = val;
//         capacity++;
//     }
//     void deleteFront(){
//         if(capacity==0){
//             cout<<-1<<endl;
//             return;
//         }
//         capacity--;
//         if(front==rear){
//           front=-1;
//             rear=-1;  
//         }else{
//           front=(front+1)%size;  
//         }
        
      
//     }
//     void deleteRear(){
//         if(capacity==0){
//             cout<<-1<<endl;
//             return;
//         }
        
//         capacity--;
//         if(front==rear){
//           front=-1;
//             rear=-1;  
//         }else{
//           rear=((rear-1)%size+size)%size;  
//         }
       
//     }
//     int getFront(){
//         if(capacity==0){
//             return -1;
//         }
//         return data[front];
//     }
//     int getRear(){
//         if(isEmpty() || rear<0){
//             return -1;
//         }
//         return data[rear];
//     }
// };
