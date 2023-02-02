#include <iostream>
#include <vector>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)  return {to_string(root->val)};
        vector<string> ans;
        if(root->left != NULL)  traverse(root->left, ans, to_string(root->val));
        if(root->right != NULL)  traverse(root->right, ans, to_string(root->val));
        return ans;
    }

    void traverse(TreeNode* cur, vector<string>& ans, string str) {

        if(cur->left == NULL && cur->right == NULL) {
            ans.push_back(str + "->" + to_string(cur->val));
        }  else if(cur->left == NULL) {
            traverse(cur->right, ans, str + "->" + to_string(cur->val));
        }  else if(cur->right == NULL) {
            traverse(cur->left, ans, str + "->" + to_string(cur->val));
        }  else {
            traverse(cur->left, ans, str + "->" + to_string(cur->val));
            traverse(cur->right, ans, str + "->" + to_string(cur->val));
        }
    }
};