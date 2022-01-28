// Reverse List In K Groups
// https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};

Node* kReverse(Node* head, int k) {
    
    if(k == 1 || head->next == NULL)
        	return head;
    
    Node *pc = new Node(-1), *pct = NULL, *prev = NULL, *curr = head, *next = NULL;
    int count = 0;
    bool flag = true;
    
    while(curr != NULL)
    { 
        if(curr->next == NULL)
        {
            if(flag)
            {
                head = curr;
                flag = false;
            }
            if(count == 0)
                pc->next = curr;
            else
            {
                curr->next = prev;
                pc->next = curr;
                pct->next = NULL;
            }
        	break;    
        }
        else if(count == 0)
        {
            pct = curr;
            prev = curr;
            curr = curr->next;
        }
        else if(count == k - 1)
        {
            if(flag)
            {
               	head = curr;
                flag = false;
            }
            next = curr->next;
            curr->next = prev;
            pc->next = curr;
            pc = pct;
            
            curr = next;
        }
        else
        {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        count = (count+1)%k;
    }
    
    return head;
    
}