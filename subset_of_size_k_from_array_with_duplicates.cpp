#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int dp[100][100];
    memset(dp, 0, sizeof(dp));


    int a[9] =     {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count[9] = {4, 1, 3, 4, 2, 6, 1, 2, 1};

    int z = 15;

    dp[0][0] = 1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j <= z; j++)
        {
            for (int k = 0; k <= count[i]; k++)
            {
                if (j - k < 0)
                    break;
                dp[i + 1][j] += dp[i][j - k];
            }
        }
    }
    
    for(int i = 0; i <= 9; i++) {
        
        if(i > 0)
            cout << a[i - 1] << "(" << count[i - 1] << ")\t";
        else
            cout << "N" << "(" << 0 << ")\t";
        for(int j = 0; j <= z; j++)
            cout << dp[i][j] << "\t";
        
        cout << endl;
    }
    return 0;
}
