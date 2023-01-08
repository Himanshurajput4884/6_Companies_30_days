
// Evaluate Reverse Polish Notation

// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

// Code:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(int i=0; i<n; i++){
            if(tokens[i]=="*" || tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="/"){
                int i1 = s.top();
                s.pop();
                int i2 = s.top();
                s.pop();
                if(tokens[i]=="*"){
                    i2 *= i1;
                }
                else if(tokens[i]=="/"){
                    i2 /= i1;
                }
                else if(tokens[i]=="+"){
                    i2 += i1;
                }
                else if(tokens[i]=="-"){
                    i2 -= i1;
                }
                s.push(i2);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};

int main(){
    vector<string> tokens = {"2","1","+","3","*"};
    Solution obj;
    cout << obj.evalRPN(tokens) << endl;
    return 0;    
}