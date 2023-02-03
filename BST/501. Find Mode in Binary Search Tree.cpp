#include <iostream>
#include <vector>
#include <stack>
#include "tree.h"

using namespace std;

class Solution {
public:
    TreeNode* pre = NULL;
    int modes = 0;
    int count = 0;
    vector<int> vec;
    vector<int> findMode(TreeNode* root) {
    
        searchBST(root);
        return vec;
    }  
    
    void searchBST(TreeNode* cur) {

        if(cur == NULL)  return;
        if(cur->left != NULL)  searchBST(cur->left);    //left

        if(pre != NULL) {                                //mid
            if(pre->val == cur->val)  count++;
            else  count = 1;
        }  else {
            count = 1;
        }
        
        if(count == modes)  vec.push_back(cur->val);
        else if(count > modes) {
            modes = count;
            vec.clear();
            vec.push_back(cur->val);
        }
        pre = cur;

        if(cur->right != NULL)  searchBST(cur->right);  //right
    }
};