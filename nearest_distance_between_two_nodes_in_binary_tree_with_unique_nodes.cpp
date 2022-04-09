#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
    
    // pair <dist, num_val_found>
    pair<int, int> solve(Node* root, int a, int b) {
        
        if(!root)
            return {-1, 0};
            
        pair<int, int> left = solve(root->left, a, b);

        if(left.second == 2)
            return left;
        
        if(left.second == 1) {

            if(root->data == a || root->data == b) {

                left.first++;
                left.second++;
                return left;
            }

            pair<int, int> right = solve(root->right, a, b);

            if(right.second == 0) {

                left.first++;
                return left;
            }
            
            // else right.second == 1
            return {left.first + right.first + 2, 2};
        }

        //left dont contain the value
        pair<int, int> right = solve(root->right, a, b);

        if(right.second == 2)
            return right;
        
        if(right.second == 1) {

            if(root->data == a || root->data == b) {

                right.first++;
                right.second++;
                return right;
            }
            
            right.first++;
            return right;
        }

        //right also dont contain the node

        if(root->data == a || root->data == b) {

            return {0, 1};
        }
        
        return {0, 0};
    }
    
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        
        // Your code here
        pair<int, int> dist = solve(root, a, b);
        
        if(dist.second == 2)
            return dist.first;
        
        return -1;
    }
};