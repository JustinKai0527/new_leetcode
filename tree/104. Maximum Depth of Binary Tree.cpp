#include <iostream>
#include <queue>

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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        
        return traverse(root, depth); 
    }

    int traverse(TreeNode* cur, int depth) {
        if(cur == NULL)  return depth;
        return max(traverse(cur->left, depth + 1), traverse(cur->right, depth + 1));
    }
};