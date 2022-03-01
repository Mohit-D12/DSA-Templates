// Max rectangle
// https://practice.geeksforgeeks.org/problems/max-rectangle/1

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

class Solution_short {
    public:
        int largestRectangleArea(vector<int> &height) {
         
            int area = 0;
            
            height.push_back(INT_MIN);        //such that each element has a smaller next element in arr
            int n = height.size();
            
            stack<int> prev;       //to store previous smaller elements
            
            for(int i = 0; i < n; i++) {
                
                while(prev.size() && height[prev.top()] > height[i]) {
                    
                    int h = height[prev.top()];
                    prev.pop();
                    
                    int prev_smaller = prev.size() ? prev.top() : -1;
                    int next_smaller = i;
                    
                    area = max(area, h * (next_smaller - prev_smaller - 1));
                }
                
                prev.push(i);
            }
            
            return area;
        }
    };

class Solution{
    void fill_left(int* arr, int n, int* l)
    {
        stack<int> s;
        s.push(-1);
        
        for(int i = 0; i < n; i++)
        {
            while(s.top() >= 0 && arr[s.top()] >= arr[i])
                s.pop();
            
            l[i] = s.top();
            s.push(i);
        }
    }
    void fill_right(int* arr, int n, int* r)
    {
        stack<int> s;
        s.push(n);
        
        for(int i = n-1; i >= 0; i--)
        {
            while(s.top() < n && arr[s.top()] >= arr[i])
                s.pop();
                
            r[i] = s.top();
            s.push(i);
        }
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int hist[m] = {0};
        int l[m], r[m];
        int max_area = 0;
        
        for(int i = 0; i < n; i++)
        {
            //fill hist
            for(int j = 0; j < m; j++)
                hist[j] = (M[i][j])? (hist[j]+1) : 0;
            
            //fill l and r
            fill_left(hist, m, l);
            fill_right(hist, m, r);
            
            
            //find areas for each elements
            for(int j = 0; j < m; j++)
                max_area = max(max_area, hist[j] * (r[j] - l[j] - 1));
        }
        
        return max_area;
    }
};

//fills l and r array in one pass
class Alernate_Solution
{
    void fill_lr(int* arr, int n, vector<int>& l, vector<int>& r)
    {
        stack<int> s;
        s.push(-1);
        
        for(int i = 0; i < n; i++)
        {
            while(s.top() >= 0 && arr[s.top()] > arr[i])
            {
                r[s.top()] = i;
                s.pop();
            }
            
            l[i] = s.top();
            
            s.push(i);
        }
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int hist[m] = {0};
        int max_area = 0;
        
        for(int i = 0; i < n; i++)
        {
            vector<int> l(m, -1), r(m, m);
            //fill hist
            for(int j = 0; j < m; j++)
                hist[j] = (M[i][j])? (hist[j]+1) : 0;
            
            //fill l and r
            fill_lr(hist, m, l, r);
            
            //find areas for each elements
            for(int j = 0; j < m; j++)
                max_area = max(max_area, hist[j] * (r[j] - l[j] - 1));
        }
        
        return max_area;
    }
};