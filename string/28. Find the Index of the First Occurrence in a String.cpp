#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        //lps   longest_border  (meaning that the prefix == suffix)
        int size = needle.size();
        vector<int> lps(size, 0);

        int prev = 0, i = 1;

        while(i < size) {

            if(needle[i] == needle[prev]){
                
                prev++;
                lps[i] = prev;
                i++;
            }  else {
                
                if(prev == 0)  lps[i++] = prev;
                else {
                    prev = lps[prev - 1];
                }
            }
        }


        //KMP algorithm
        int Size = haystack.size();
        int h_ptr = 0;
        int n_ptr = 0;

        while(h_ptr < Size) {

            if(haystack[h_ptr] == needle[n_ptr]) {

                h_ptr++;
                n_ptr++;
                if(n_ptr == size)  return h_ptr - n_ptr;
            }  else {

                if(n_ptr == 0)  h_ptr++;
                else {
                    n_ptr = lps[n_ptr - 1];
                }
            }
        }


        return -1;
    }
};
