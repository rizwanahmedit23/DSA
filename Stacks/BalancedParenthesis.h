#include <stack>
bool isBalanced(string expression) 
{
    // Write your code here
    stack<char> s;
    int n = expression.size();
    for(int i=0;i<n;i++){
		if(expression[i]=='(' || expression[i]=='{' || expression[i]=='['){
			s.push(expression[i]);
        }
        else if(expression[i]==')' || expression[i]=='}' || expression[i]==']'){
			if(s.empty())	return false;
            if(expression[i]==')' && s.top()=='(')	s.pop();
            else if(expression[i]=='}' && s.top()=='{')	s.pop();
            else if (expression[i]==']' && s.top()=='[')	s.pop();
            else	return false;
        }
    }
    return s.empty();
}