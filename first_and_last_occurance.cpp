#include<bits/stdc++.h>
using namespace std;

int first_occurance(int* arr, int n, int key)
{
    int result = -1;

    if (n == 0)
        return result;
    
    int s = 0, e = n-1;
    int mid = s + (e - s)/2;

    while(s <= e)
    {
        if (arr[mid] == key)
        {
            result = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
        
        mid = s + (e - s)/2;
    }

    return result;
}


int last_occurance(int* arr, int n, int key)
{
    int result = -1;

    if (n == 0)
        return result;
    
    int s = 0, e = n-1;
    int mid = s + (e - s)/2;

    while(s <= e)
    {
        if (arr[mid] == key)
        {
            result = mid;
            s = mid + 1;
        }
        else if (arr[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
        
        mid = s + (e - s)/2;
    }

    return result;
}


int main()
{
    int arr[10] = {1, 1, 2, 3, 3, 3, 4, 4, 5, 6};
    cout << first_occurance(arr, 10, 3) << endl;
    cout << last_occurance(arr, 10, 3);
}