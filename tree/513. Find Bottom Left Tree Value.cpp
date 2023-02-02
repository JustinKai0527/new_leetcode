#include "tree.h"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int ans;
        bool f = false;
        if(root != NULL)  q.push(root);

        while(!q.empty()) {
            
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if(f) {
                    f = false;
                    ans = cur->val;
                }
                if(cur->left != NULL)  q.push(cur->left);
                if(cur->right != NULL)  q.push(cur->right);
            }
            f = true;
        }
        
        return ans;
    }
};


class Solution {
public:
    int Max = RAND_MAX;
    int Depth = 0;
    int result = 0;
    int findBottomLeftValue(TreeNode* root) {
        
        traverse(root, 0);
        return result;
    }

    void traverse(TreeNode* cur, int depth) {
        
        if(cur->left == NULL && cur->right == NULL) {
            
            if(Depth < depth) {
                Depth = depth;
                result = cur->val;
            }
        }
        if(cur->left != NULL)  traverse(cur->left, depth + 1);
        if(cur->right != NULL)  traverse(cur->right, depth + 1);
    }
};