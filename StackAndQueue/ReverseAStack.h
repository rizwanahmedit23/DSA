void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if(input.empty())	return;

    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    int item=extra.top();
    extra.pop();
	while(!extra.empty()){
		input.push(extra.top());
		extra.pop();
	}
    reverseStack(input, extra);
    input.push(item);
    return;
}