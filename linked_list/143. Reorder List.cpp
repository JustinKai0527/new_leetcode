#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {

        vector<ListNode*> nodes;
        get(nodes, head);
        int size = nodes.size();
        int left = 0, right = size - 1;
        // cout <<size <<endl;
        while(left < right) {
            nodes[left++]->next = nodes[right];
            // cout <<left<<right<<endl;
            nodes[right--]->next = nodes[left];
            // cout <<left<<right<<endl;
        }
        (size % 2 == 1)?  nodes[right]->next = NULL: nodes[left]->next = NULL;
        return;
    }
    
    void get(vector<ListNode*>& nodes, ListNode* cur) {

        if(cur == NULL)  return;
        nodes.push_back(cur);
        get(nodes, cur->next);
        return;
    }
};