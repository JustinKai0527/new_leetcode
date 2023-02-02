#include <iostream>
#include "tree.h"

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root,targetSum);
    }
    bool check(TreeNode* cur, int targetSum){
        if(cur == NULL)    return false;
        else if(cur->val == targetSum && cur->right == NULL && cur->left == NULL)    return true;
        targetSum-=cur->val;
        return check(cur->left, targetSum) || check(cur->right, targetSum);
    }
};