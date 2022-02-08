// Next Smaller Element
// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> res(n);
    stack<int> small;
    small.push(-1);
    
    
    int i = n - 1;
    while(i >= 0)
    {
        if(arr[i] > small.top())
        {
            res[i] = small.top();
            small.push(arr[i]);
        }
        else
        {
            while(arr[i] <= small.top())
                small.pop();
            res[i] = small.top();
            small.push(arr[i]);
        }
        i--;
    }
    
    return res;
}