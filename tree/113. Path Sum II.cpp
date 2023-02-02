#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vec;
        check(root, targetSum, vec);
        return result;
    }

    void check(TreeNode* root, int targetSum, vector<int> vec) {

        if(root == NULL)  return;
        if(root->val == targetSum) {
            if(root->left == NULL && root->right == NULL) {
                vec.push_back(root->val);
                result.push_back(vec);
                return;
            }
        }
        if(root->left != NULL) {
            vec.push_back(root->val);
            check(root->left, targetSum - root->val, vec);
            vec.pop_back();
        }
        if(root->right != NULL) {
            vec.push_back(root->val);
            check(root->right, targetSum - root->val, vec);
            vec.pop_back();
        }
    }
};