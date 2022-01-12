#include <bits/stdc++.h>
using namespace std;

int linear_search(int* arr, int n, int key)
{
    if (n == 0)
        return -1;                                          // no more elements left to compare
    
    if (arr[0] == key)
        return 0;                                           //as current index is 0

    int result = linear_search(arr + 1, n - 1, key);

    if (result == -1)                                       //value not exist in remaing array
        return -1;

    else
        return 1 + result;


}

int main()
{
    int arr[5] = {7, 3, 21, 5, 8};
    
    cout << linear_search(arr, 5, 5);
}