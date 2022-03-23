#include<unordered_map>
string uniqueChar(string str) {
	// Write your code here
    unordered_map<char, bool> ourmap;
    string result = "";
	for(int i=0;i<str.size();i++){
        if(ourmap.count(str[i]) == 0){
            result +=str[i];
            ourmap[str[i]] = true;
        }
    }    
    return result;
}