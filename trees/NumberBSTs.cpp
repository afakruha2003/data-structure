#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the number of BSTs using Dynamic Programming
int countBST(int n)
{
    vector<int> dp(n + 1, 0); // int dp[n + 1] = {0};
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Number of BSTs with " << n << " nodes: " << countBST(n) << endl;
    return 0;
}
