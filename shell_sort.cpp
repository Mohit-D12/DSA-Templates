#include<bits/stdc++.h>
using namespace std;

void shell_sort(int* a, int n)
{
    int gap = n / 2;

    while(gap > 0)
    {
        for(int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;
            for(j = i; j >= gap && a[j-gap] > temp; j-= gap)
                a[j] = a[j - gap];
            
            a[j] = temp;
        }
        gap /= 2;
    }
}

void print(int* arr, int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    
    cout << endl;
}

int main()
{
    int n = 10;
    int a[10] = {10, 2, 6, 19, 21, 2, 11, 16, 9, 31};

    shell_sort(a, n);
    print(a, n);

    return 0;
}