// Clone a linked list with next and random pointer
// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{
    Node* clone_and_merge(Node* head)
    {
        Node* a = head;
        Node* b;
        
        while(a != NULL)
        {
            b = new Node(a->data);
            b->next = a->next;
            a->next = b;
            
            a = b->next;
        }
    }
    
    void clone_random_pointer(Node* head)
    {
        Node* a = head;
        
        while(a != NULL)
        {
            if(a->arb != NULL)
                a->next->arb = a->arb->next;
            
            a = a->next->next;
        }
    }
    
    Node* split_alternate(Node* head)
    {
        if(head == NULL)
            return NULL;
        
        Node* a = head, *result = a->next;
        Node* b;
        
        while(a->next != NULL)
        {
            b = a->next;
            a->next = b->next;
            a = b;
        }
        
        return result;
    }

  public:
    Node *copyList(Node *head)
    {
        if(head == NULL)
            return NULL;
        
        clone_and_merge(head);          // makes ll from 1-2-3-N to 1-1-2-2-3-3-N
        clone_random_pointer(head);     // copies random pointers of cloned nodes
        return split_alternate(head);   // splits the cloned nodes into a seperate ll and return its head
    }

};