// Quick Sort on Linked List
// https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1#

#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class quicksort_updating_head_pointer
{
    void quickSort(Node **result) {
        if(*result == NULL || (*result)->next == NULL)
            return;
            
        Node* head = *result;
        Node* sh = new Node(-1), *s = sh;
        Node* gh = new Node(-1), *g = gh;
        
        Node* curr = head->next;
        while(curr)
        {
            if(curr->data <= head->data)
            {
                s->next = curr;
                s = s->next;
            }
            else
            {
                g->next = curr;
                g = g->next;
            }
            
            curr = curr->next;
        }
        
        g->next = NULL;
        head->next = NULL;
        s->next = NULL;
        
        curr = sh;
        sh = sh->next;
        delete curr;
        
        curr = gh;
        gh = gh->next;
        delete curr;
        
        quickSort(&gh);
        quickSort(&sh);
        
        if(sh != NULL)
        {
            curr = sh;
            while(curr->next)
                curr = curr->next;
            
            curr->next = head;
        }
        else
            sh = head;
        
        head->next = gh;
        
        *result = sh;
    }
};

class quicksort_returning_head_pointer
{
    Node* quick_sort(Node* head)
    {
        if(head == NULL || head->next == NULL)
            return head;

        Node* sh = new Node(-1);
        Node* gh = new Node(-1);
        Node* s = sh, *g = gh, *curr = head->next;

        while(curr)
        {
            if(curr->data <= head->data)
            {
                s->next = curr;
                s = s->next;
            }
            else
            {
                g->next = curr;
                g = g->next;
            }

            curr = curr->next;
        }

        g->next = NULL;
        s->next = NULL;
        head->next = NULL;

        s = sh->next;
        g = gh->next;
        delete sh, gh;

        sh = quick_sort(sh->next);
        gh = quick_sort(gh->next);

        head->next = gh;
        if(sh == NULL)
            sh = head;
        else
        {
            curr = sh;
            while(curr->next)
                curr = curr->next;
            
            curr->next = head;
        }

        return sh;
    }
};