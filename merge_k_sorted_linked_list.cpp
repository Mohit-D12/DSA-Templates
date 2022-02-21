// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct compare
{
    bool operator() (ListNode* a,  ListNode* b)
    {
        return a->val > b->val;
    }
};
class Solution {
    
 public:   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head = new ListNode(-1);
        ListNode* node;
        
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        
        for(auto node: lists)
            if(node)
                q.push(node);
        
        node = head;
        while(q.size()) {
        
            node->next = q.top();
            q.pop();
            
            node = node->next;
            
            if(node->next)
                q.push(node->next);
        }
        
        return head->next;
    }
};