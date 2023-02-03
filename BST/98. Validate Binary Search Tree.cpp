#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;


class Solution {
public:
    long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        // 中序遍历，验证遍历的元素是不是从小到大
        if (maxVal < root->val) maxVal = root->val;
        else return false;
        bool right = isValidBST(root->right);

        return left && right;
    }
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        vector<int> vec;
        inorder(root, vec);
        int size = vec.size();
        for(int i = 0; i + 1 < size; i++) {
            if(vec[i] > vec[i + 1])  return false;
        }

        return true;
    }

    void inorder(TreeNode* cur, vector<int>& vec) {
        
        if(cur == NULL)  return;
        if(cur->left != NULL)  inorder(cur->left, vec);
        vec.push_back(cur->val);
        if(cur->right != NULL)  inorder(cur->right, vec);  
    }
};