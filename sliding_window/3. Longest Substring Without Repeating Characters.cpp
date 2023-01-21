#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int size = s.size();
        int len = 0;
        unordered_map<char, int> map;

        for(int i = 0, j = 0; i < size; i++) {
            
            map[s[i]]++;
            if(map[s[i]] == 1)  len = (i - j + 1);
            while(map[s[i]] != 1) {
                
                map[s[j]]--;
                j++;
            }
        }

        return len;
    }
};