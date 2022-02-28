// 60. Permutation Sequence
// https://leetcode.com/problems/permutation-sequence/

#include<bits/stdc++.h>
using namespace std;

#define MAX_FACT 10

class Solution {
    
    string permute(int n, int k, int* fact, set<int>& h) {
        
        string s = "";
        
        if(n == 0)
            return s;
        
        // fill the prefix of string which occurs in ascending order
        while(n > 0 && fact[n - 1] > k) {
            
            s += *h.begin() + '0';
            h.erase(h.begin());
            n--;
        }
        
        //find the next character of string
        if(n > 0) {
            
            int pos = --k / fact[n - 1];        //next digit will be pos'th smallest digit from unused digits
            
            auto it = next(h.begin(), pos);
            s += *it + '0';

            h.erase(it);
            
            //use recursion to find the remaining string
            k = k % fact[n - 1];
            s += permute(n - 1, k + 1, fact, h);
        }
        
        return s;
    }
    
  public:
    
    string getPermutation(int n, int k) {
        
        int fact[MAX_FACT] = {1};     //stores factorial upto 9
        set<int> h;             //stores unused digits from 1 to n (in ascending order)
        
        for(int i = 1; i < MAX_FACT; i++)
            fact[i] = i * fact[i - 1];
        
        for(int i = 1; i <= n; i++)
            h.insert(i);
        
        return permute(n, k, fact, h);
    }
};