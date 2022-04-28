// Count smaller elements
// https://practice.geeksforgeeks.org/problems/count-smaller-elements2214/1/?track=gts-searching&batchId=397

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

class Solution{
    public:
    vector<int> constructLowerArray(int *arr, int n) {
    
        // Your code goes here
        tree < int ,  null_type ,  less_equal<int> ,  rb_tree_tag ,  tree_order_statistics_node_update > h;
        vector<int> result(n);

        for(int i = n - 1; i >= 0; i--) {

            result[i] = h.order_of_key(arr[i]);
            h.insert(arr[i]);
        }

        return result;
    }
};
