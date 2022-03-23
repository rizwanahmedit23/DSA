#include<stack>
int countBracketReversals(string input) {
	// Write your code here
    if(input.size()%2!=0)	return -1;			//String of odd size cant be balanced
    stack<int> s;
    for(int i=0;i<input.size();i++){
        if(input[i] == '{'){					//if '{' PUSH IT
            s.push(input[i]);
        }
        else{									//else 
            if(s.empty() || s.top()== '}'){				
				s.push(input[i]);
            }
            else{
				s.pop();
            }
        }
    }
    int count=0;
    int c1,c2;
    while(!s.empty()){
        c1=s.top();
        s.pop();
        c2=s.top();
        s.pop();
            
        if(c1==c2){
            count++;
        }
        else{
            count=count+2;
        }
    }
    return count;
}