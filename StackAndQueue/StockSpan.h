#include<stack>
int* stockSpan(int *price, int size)  {
	// Write your code here
    int* span=new int[size];
    stack<int> s;
    for(int i=0;i<size;i++){
			// if(s.empty()){
			// span[i]=i+1;
			// s.push(i);
			// // continue;
			// }
			// else{
			// if(price[s.top()]>=price[i]){
			// span[i]=i-s.top();
			// s.push(i);
			// }
			// else{
                while(!s.empty() && price[s.top()]<price[i] ){
					s.pop();
                }
                if(s.empty())	span[i]=i+1;
                else	span[i]=i-s.top();
                s.push(i);
        //     }
        // }
    }
    return span;
}