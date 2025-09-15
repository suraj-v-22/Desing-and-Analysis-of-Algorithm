#include <iostream>
using namespace std;

#define MAX 10

int dp[MAX][MAX];

int knapsack(int n, int W, int profit[], int weight[])                  // TC - O(nxW)
{                                                                       // SC - O(nxW)
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weight[i] > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(dp[i - 1][w], profit[i] + dp[i - 1][w - weight[i]]);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n, W;
    int profit[MAX];
    int weight[MAX];

    cout << "Enter the number of items : ";
    cin >> n;

    cout << "Enter the weights : ";
    for (int i = 1; i <= n; i++)
        cin >> weight[i];

    cout << "Enter the profits : ";
    for (int i = 1; i <= n; i++)
        cin >> profit[i];

    cout << "Enter the knapsack capacity : ";
    cin >> W;

    int result = knapsack(n, W, profit, weight);

    cout << "\nDP TABLE : \n";
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << dp[i][w] << "\t";
        }
        cout << "\n";
    }
    cout << "Maximum Profit = " << result << endl;
}