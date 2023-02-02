#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL)  return root2;
        else if(root2 == NULL)  return root1;
        merge(root1, root2);
        return root1;
    }

    void merge(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL && root2 == NULL)  return;

        root1->val += root2->val;
        
        if(root1->left == NULL && root2->left != NULL)  root1->left = new TreeNode(0);
        else if(root1->left != NULL && root2->left == NULL)  root2->left = new TreeNode(0);
        merge(root1->left, root2->left);
        if(root1->right == NULL && root2->right != NULL)  root1->right = new TreeNode(0);
        else if(root1->right != NULL && root2->right == NULL)  root2->right = new TreeNode(0);
        merge(root1->right, root2->right);
    }
};


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) return t2; // 如果t1为空，合并之后就应该是t2
        if (t2 == NULL) return t1; // 如果t2为空，合并之后就应该是t1
        // 修改了t1的数值和结构
        t1->val += t2->val;                             // 中
        t1->left = mergeTrees(t1->left, t2->left);      // 左
        t1->right = mergeTrees(t1->right, t2->right);   // 右
        return t1;
    }
};