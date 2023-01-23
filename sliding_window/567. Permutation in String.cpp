#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> check;
        unordered_map<char, int> ans;

        for(char ch: s1) {
            check[ch]++;
        }

        int size = s1.size();
        int s2_size = s2.size();
        int count = 0;

        for(int i = 0, j = 0; i < s2_size; i++) {
            

            if(check.find(s2[i]) == check.end()) {
                ans.clear();
                j = i + 1;
                continue;
            }

            count++;
            ans[s2[i]]++;

            if(count > size) {
                ans[s2[j++]]--;
                count--;
            }

            if(count == size) {
                if(checking(check, ans))  return true;
            }
        }

        return false;
    }

    bool checking(unordered_map<char, int>& check, unordered_map<char, int>& ans) {

        for(auto it: check) {
            if(ans[it.first] != it.second)  return false;
        }

        return true;
    }
};


