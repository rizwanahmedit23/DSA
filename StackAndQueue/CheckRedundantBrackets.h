#include<stack>
bool checkRedundantBrackets(string expression) {
	// Write your code here
	stack<char> s;
    int i=0;
    while(i<expression.size()){
        while(expression[i]!='}' &&expression[i]!=')'){
            s.push(expression[i]);
            i++;
        }
        i++;
        int count=0;
        while(s.top()!='{' && s.top()!='('){
            s.pop();
            count++;
        }
        s.pop();
        if(count<=1)	return true;
    }
    return false;
}