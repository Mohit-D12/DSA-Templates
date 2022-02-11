// Maximum Rectangular Area in a Histogram
// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void fill_next_smaller_element(long long* arr, int n, int* r)
    {
        stack<long long> s;
        s.push(n);
        
        for(int i = n-1; i >= 0; i--)
        {
            while(s.top() < n && arr[s.top()] >= arr[i])
                s.pop();
                    
            r[i] = s.top();
            s.push(i);
        }
    }
    void fill_prev_smaller_element(long long* arr, int n, int* l)
    {
        stack<long long> s;
        s.push(-1);
        
        for(int i = 0; i < n; i++)
        {
            while(s.top() >= 0 && arr[s.top()] >= arr[i])
                s.pop();
                    
            l[i] = s.top();
            s.push(i);
        }
    }
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long area = 0;
        int* r = new int[n];
        int* l = new int[n];
        
        fill_next_smaller_element(arr, n, r);
        fill_prev_smaller_element(arr, n, l);
        
        for(int i = 0; i < n; i++)
            area = max(area, arr[i] * (r[i] - l[i] - 1));
        
        delete r, l;
        return area;
    }
};