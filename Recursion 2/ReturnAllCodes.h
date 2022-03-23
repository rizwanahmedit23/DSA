// #include <string.h>
// using namespace std;
// int getCodes(string input, string output[10000])
//  {
//     /*
//     You are given the input text and output string array. Find all possible codes and store in the output string array. DonÃÂ¢ÃÂÃÂt print the codes.
//     Also, return the number of codes return to the output string. You do not need to print anything.
//     */
//    if(input.empty())
//    {
//        output[0]="";
//        return 1;
//    }
//    int firstNumber=input[0]-'0';
//    char firstChar=firstNumber +'a'-1;
//    char doubleNumber='\0';
//    string result1[10000],result2[10000];
//    int p=getCodes(input.substr(1),result1);
//    int q=0;
//    if(input[1]!='\0')
//    {
//        int x=firstNumber*10;
//        int y=x+(input[1]-'0');
//        if(y>=10 && y<=26)
//        {
//            doubleNumber=y+'a'-1;
       
//        q=getCodes(input.substr(2),result2);
//        }
//    }
//    int count=0;
//    for(int i=0;i<p;i++)
//    {
//        output[count]=firstChar+result1[i];
//        count++;
//    }
//     if(doubleNumber!='\0')
//     {
//         for(int i=0;i<q;i++)
//         {
//             output[count]=doubleNumber+result2[i];
//             count++;
//         }
//     }
//     return count;
//  }


#include <string>
using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. DonÃ¢ÂÂt print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.length() == 0){
        output[0] = "";
        return 1;
    }
    if(input.length() == 1){
        int num = input[0]-'0';
    	char c = num + 'a' - 1;
        output[0]= c;
    	return 1;
    }
    int smallOutput = getCodes(input.substr(1), output);
    int num = input[0]-'0';
    char c = num + 'a' - 1;
    for(int i= 0;i<smallOutput;i++){
        output[i] = c+output[i];
    }
    int smallOutput2 = 0;
    if(input.length() >=1){
        int num2 = 10 * (input[0] - '0') + input[1] - '0';
        char c2 = num2 + 'a' - 1;
        
        if(num2 <= 26){
            smallOutput2 = getCodes(input.substr(2), output+smallOutput);
            for(int i= smallOutput;i<smallOutput+smallOutput2;i++){
                output[i] = c2+output[i];
            }
        }
    }
    return smallOutput + smallOutput2;    
}


// #include <string.h>
// #include <bits/stdc++.h>
// using namespace std;

// void help(string input,string out,vector<string> &str){
//     if(input.size()==0){
//         str.push_back(out);
//         return;
//     }
//     char c1=(input[0]-48)+96;
    
    
//     if(input[0]=='0')
//         return;
    
//     help(input.substr(1),out+c1,str);
    
//     if(input.size()>1){
//         int d=(input[0]-48)*10+(input[1]-48);
//         if(d>26)
//             return;
//         char c2=96+d;
//         help(input.substr(2),out+c2,str);
//     }
    
// }


// int getCodes(string input, string output[10000]) {
//     /*
//     You are given the input text and output string array. Find all possible codes and store in the output string array. DonÃ¢ÂÂt print the codes.
//     Also, return the number of codes return to the output string. You do not need to print anything.
//     */
//     vector<string> str;
//     string out="";
//     help(input,out,str);
    
//     for(int i=0;i<str.size();i++)
//         output[i]=str[i];
    
//     int x=str.size();
    
//     return x;

    
// }
