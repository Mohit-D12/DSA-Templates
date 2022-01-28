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

Node* kReverse(Node* head, int k) 
{
    Node* curr = head;
    Node* prev = NULL, *next = NULL;
    int cnt = 0;

    // Reversing the first K nodes of the given linked list.
    while (curr != NULL && cnt < k) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    // If some nodes are still left, then we pass it to the recursive function.
    if (next != NULL) 
    {
        head->next = kReverse(next, k);
    }

    return prev;
}

Node* kReverse2(Node* head, int k) {
    
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