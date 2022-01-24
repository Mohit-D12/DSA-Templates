// Merge 2 Sorted Arrays Without Extra Space
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#

class Solution{
    
    int get(int* a, int* b, int n, int m, int index)
    {
        if(index < n)
            return a[index];
        return b[index - n];
    }
    int set(int* a, int* b, int n, int m, int index, int val)
    {
        if(index < n)
            a[index] = val;
        else
            b[index - n] = val;
    }

public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int gap = (n + m) / 2;
	    while(gap > 0)
        {
            for(int i = gap; i < n + m; i++)
            {
                int j, temp = get(arr1, arr2, n, m, i);
                
                for(j = i; j >= gap && get(arr1, arr2, n, m, j - gap) > temp; j-= gap)
                    set(arr1, arr2, n, m, j, get(arr1, arr2, n, m, j - gap));
                    
                set(arr1, arr2, n, m, j, temp);
            }
            gap /= 2;
        }
        
	}
};