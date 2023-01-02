#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;

        for(string str: tokens) {
            s.push(str);
            if(str == "+" || str == "-" || str == "*" || str == "/") {

                s.pop();
                int right = stoi(s.top());
                s.pop();
                int left = stoi(s.top());
                s.pop();
                if(str == "+") {
                    s.push(to_string(left + right));
                }  else if(str == "-") {
                    s.push(to_string(left - right));
                }  else if(str == "*") {
                    s.push(to_string(left * right));
                }  else if(str == "/") {
                    s.push(to_string(left / right));
                }
            }
        }

        return stoi(s.top());
    }
};