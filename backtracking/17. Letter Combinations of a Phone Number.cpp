#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> phone;
    string str;

    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0)  return result;
        for(int i = 0; i < 5; i++) {
            string str;
            for(int j = 0; j < 3; j++) {
                str += (char)(97 + 3*i + j);
            }
            phone.push_back(str);
        }
        phone.push_back("pqrs");
        phone.push_back("tuv");
        phone.push_back("wxyz");
        // for(string s: phone) {
        //     cout <<s<<endl;
        // }
        // cout <<phone[digits[0] - 50];
        backtrack(digits, 0);
        return result;
    }

    void backtrack(string digits, int n) {

        if(n == digits.size()) {
            result.push_back(str);
            return;
        }

        for(char ch: phone[digits[n] - 50]) {

            str.push_back(ch);
            backtrack(digits, n + 1);
            str.pop_back();
        }
    }
};