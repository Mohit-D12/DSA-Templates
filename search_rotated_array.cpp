#include<bits/stdc++.h>
using namespace std;

class Solution
{

    int get_pivot(vector<int>& arr, int n) {
   
        int s = 0, e = n-1;
        int mid = s + (e - s)/2;
        while (s < e) {
       
            if(arr[mid] >= arr[0])
                s  = mid + 1;
            else
                e = mid;
            mid = s + (e - s)/2;
        }
        return s;
    }

    int findPosition(vector<int>& arr, int n, int k) {
   
        // Write your code here.
        // Return the position of K in ARR else return -1.
        int pivot = get_pivot(arr, n);
        
        if(arr[0] == k)
            return 0;

        int s, e, mid;
        
        if (arr[0] > k) {
       
            s = pivot;
            e = n-1;
        }
        else {
        
            s = 0;
            e = pivot-1;
        }

        mid = s + (e - s)/2;
        while (s <= e)
        {
            if(arr[mid] == k)
                return mid;
            if(arr[mid] > k)
                e = mid - 1;
            else
                s = mid + 1;
            mid = s + (e-s)/2;
        }
        return -1;
    }

};
