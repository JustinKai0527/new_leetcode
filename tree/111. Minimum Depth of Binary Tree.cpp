#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)  return 0;
        int depth = 1;
        
        return traverse(root, depth); 
    }

    int traverse(TreeNode* cur, int depth) {
        if(cur->left == NULL && cur->right == NULL)  return depth;       //mid
        else if(cur->left == NULL) {
            return traverse(cur->right, depth + 1);                     //left
        }  else if(cur->right == NULL) {
            return traverse(cur->left, depth + 1);                      //right
        }  else {
            return min(traverse(cur->left, depth + 1), traverse(cur->right, depth + 1));
        }
    }
};