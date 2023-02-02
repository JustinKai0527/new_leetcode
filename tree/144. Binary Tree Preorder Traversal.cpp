#include <iostream>
#include <stack>
#include <vector>
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