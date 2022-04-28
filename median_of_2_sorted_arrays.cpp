// Median of two sorted arrays
// https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1/?track=gts-searching&batchId=397

#include<bits/stdc++.h>
using namespace std;

class Solution{

    bool is_valid(int i, int n) {

        return (i >= 0 && i < n);
    }

    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n = array1.size();
        int m = array2.size();
        
        if(n < m)
            return MedianOfArrays(array2, array1);

        bool is_odd = (n + m) & 1;
        int i1, i2;
        int s = 0, e = n - 1;
        int l1, l2, r1, r2;

        while(s <= e) {

            i1 = s + (e - s)/2;
            i2 = (m + n - 1)/2 - i1;
            
            if(i2 > m) {
                
                s = i1 + 1;
                continue;
            }
            if(i2 < 0) {
                
                e = i1 - 1;
                continue;
            }
            

            l1 = is_valid(i1, n)? array1[i1] : INT_MIN;
            r1 = is_valid(i1 + 1, n)? array1[i1 + 1] : INT_MAX;

            l2 = is_valid(i2 - 1, m)? array2[i2 - 1] : INT_MIN;
            r2 = is_valid(i2, m)? array2[i2] : INT_MAX;
        

            if(max(l1, l2) <= min(r1, r2)) {

                if(is_odd)
                    return max(l1, l2);

                return (max(l1, l2) + min(r1, r2))/2.0;
            }
            
            if(l1 > r2)
                e = i1 - 1;
            else
                s = i1 + 1;
        }
    }
};