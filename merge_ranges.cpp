#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.first >= b.first)
        return true;
    return false;
}

int main()
{
    int n;
    pair<int, int> arr[n];
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
    }

    sort(arr, arr+n, compare);

    stack<pair<int, int>> result;

    result.push(arr[0]);

    for(int i = 1; i < n; i++)
    {
        pair<int, int> temp = result.top();
        if (temp.second < arr[i].first)
            result.push(arr[i]);
        else
        {
            temp.second = max(temp.second, arr[i].second);
            result.pop();
            result.push(temp);
        }
    }

    while(result.empty())
    {
        pair<int, int> temp = result.top();
        cout << temp.first << " " << temp.second << endl;
        result.pop();
    }


    return 0;

}