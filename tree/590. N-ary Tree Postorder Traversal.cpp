#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {    //recursion solution
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }

    void traversal(Node* cur, vector<int> ans) {
        if(cur == NULL)  ans.push_back(cur->val);
        for(int i = cur->children.size() - 1; i >= 0; i--) {
            traversal(cur->children[i], ans);
        }
    }
};