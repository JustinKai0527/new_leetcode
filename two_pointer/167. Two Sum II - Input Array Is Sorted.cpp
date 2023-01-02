#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int size = numbers.size();
        int i = 0, j = size - 1;

        while(i < j) {
            int sum = numbers[i] + numbers[j];

            if(sum == target)  break;

            if(sum < target) {
                i++;
                continue;
            }  else if(sum > target && i - 1 > 0 && numbers[i] < 0) {
                i--;
                continue;
            }  else if(sum > target) {
                j--;
                continue;
            }

        }

        return {i + 1, j + 1};
    }
};