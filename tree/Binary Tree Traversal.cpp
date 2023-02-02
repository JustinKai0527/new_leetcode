#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "tree.h"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;              //FILO
        vector<int> vec;
        if(root == NULL)  return vec;

        st.push(root);
        while(!st.empty()) {

            TreeNode* tmp = st.top();
            st.pop();
            vec.push_back(tmp->val);
            if(tmp->right != NULL)  st.push(tmp->right);     //because FILO  so first push right
            if(tmp->left != NULL)  st.push(tmp->left);
        }

        return vec;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur != NULL || !st.empty()) {
            if(cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }  else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;              //FILO
        vector<int> vec;
        if(root == NULL)  return vec;

        st.push(root);
        while(!st.empty()) {

            TreeNode* tmp = st.top();
            st.pop();
            vec.push_back(tmp->val);                       //mid
            if(tmp->left != NULL)  st.push(tmp->left);     //left
            if(tmp->right != NULL)  st.push(tmp->right);   //right 
        }
        reverse(vec.begin(), vec.end());              //mid left right -> right left mid

        return vec;
    }
};
