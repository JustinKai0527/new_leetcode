#include <iostream>
#include "tree.h"
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        queue<TreeNode*> q;
        if(root != NULL)  q.push(root);

        while(!q.empty()) {

            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if(i == size - 1)  vec.push_back(cur->val);
                if(cur->left != NULL)  q.push(cur->left);
                if(cur->right != NULL)  q.push(cur->right);
            }
        }

        return vec;
    }
};


class Solution {
public:
    int maxDepth = 0;
    vector<int> vec;
    vector<int> rightSideView(TreeNode* root) {

        traverse(root, 0);

        return vec;
    }

    void traverse(TreeNode* root, int depth) {                   //preorder   
  
        if(depth == 0)  return;
        if(root != NULL && depth > maxDepth) {
            maxDepth = depth;
            vec.push_back(root->val);
        }

        if(root->right != NULL)  traverse(root->right, depth + 1);
        if(root->left != NULL)  traverse(root->left, depth + 1);
    }
};


