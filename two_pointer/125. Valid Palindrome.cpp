#include <ctype.h>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        
        int size = s.size();
        for(int i = 0, j = size - 1; i < j; ) {
            
            int ch1, ch2;
            ch1 = tolower(s[i]);
            ch2 = tolower(s[j]);
            
            if(ch1 < 97 && ch1 > 122)  i++;
            if(ch2 < 97 && ch2 > 122)  j--;
            if(ch1 == ch2) {
                i++;
                j--;
            } else  return false;
        }

        return true;
    }
};