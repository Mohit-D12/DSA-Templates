#include<bits/stdc++.h>
using namespace std;

class Node {    
public:
    Node* val[26];
    bool is_terminal;
    
    Node() {
        
        for(int i = 0; i < 26; i++)
            this->val[i] = NULL;
        this->is_terminal = false;
    }
    
    int count_children() {
        
        int count = 0;
        
        for(int i = 0; i < 26; i++) {
            
            if(val[i])
                count++;
        }
        
        return count;
    }
    
    int get_only_child() {
        
        for(int i = 0; i < 26; i++) {
            
            if(val[i])
                return i;
        }
        
        return -1;
    }
};
    
class Trie {
  
  public:  
    Node* head;
    
    Trie() {
        
        head = new Node();
    }
    
    void insert(string word) {
        
        Node* curr = head;
        
        for(char ch: word) {
            
            if(curr->val[ch - 'a'] == NULL)
                curr->val[ch - 'a'] = new Node;
            
            curr = curr->val[ch - 'a'];
        }
        
        curr->is_terminal = true;
    }
    
    
    
    void find_prefix_util(Node* curr, vector<string>& result, string pref) {
        
        // 1. curr wont be null
        
        int count = curr->count_children();
        
        if(count == 0) {
            
            if(pref.length() > 0)
                result.push_back(pref);
            
            return;
        }
        
        if(count == 1) {
            
            if(pref.length() == 0)
                pref.push_back(curr->get_only_child() + 'a');
            
            result.push_back(pref);
            return;
        }
        
        for(int i = 0; i < 26; i++) {
            
            if(curr->val[i] != NULL) {
                
                pref.push_back('a' + i);
                find_prefix_util(curr->val[i], result, pref);
                pref.pop_back();
            }
        }
    }
    
    vector<string> find_prefix() {
        
        vector<string> result;
        string pref = "";
        find_prefix_util(this->head, result, pref);
        return result;
    }
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        Trie t;
        
        for(int i = 0; i < n; i++)
            t.insert(arr[i]);
        
        return t.find_prefix();
    }
    
};