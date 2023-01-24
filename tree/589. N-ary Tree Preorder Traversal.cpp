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
    vector<int> preorder(Node* root) {

        vector<int> ans; 
        if(root == NULL)  return ans;

        stack<Node*> st;
        st.push(root);

        while(!st.empty()) {

            ans.push_back(st.top()->val);
            vector<Node*> tmp = st.top()->children;
            st.pop();
            for(int i = tmp.size() - 1; i >= 0; i--) {
                st.push(tmp[i]);
            }
        }

        return ans;
    }
};