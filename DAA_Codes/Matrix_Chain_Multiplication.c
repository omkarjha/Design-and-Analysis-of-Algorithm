#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications for chain matrix
int matrixChainOrder(int dimensions[], int n)
{
    int dp[n][n]; // Dynamic programming table

    // Initialize the dp table with 0
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // Fill the dp table diagonally
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dimensions[n + 1];

    printf("Enter the dimensions of matrices:\n");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &dimensions[i]);
    }

    int minMultiplications = matrixChainOrder(dimensions, n + 1);

    printf("Minimum number of multiplications: %d\n", minMultiplications);

    return 0;
}
