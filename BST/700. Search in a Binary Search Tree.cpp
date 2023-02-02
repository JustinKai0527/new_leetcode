#include <iostream>
#include "tree.h"

using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)  return NULL;
        if(root->val == val)  return root;
        else if(root->val < val)  return searchBST(root->right, val);
        else if(root->val > val)  return searchBST(root->left, val);
        return NULL;
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        while(root != NULL) {
            
            if(root->val == val)  break;
            else if(root->val > val)  root = root->left;
            else if(root->val < val)  root = root->right;
        }

        return root;
    }
};