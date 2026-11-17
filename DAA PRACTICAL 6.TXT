// Practical 6: Matrix Chain Multiplication
// Purpose: To find the minimum number of scalar multiplications
// required to multiply a chain of matrices.

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // Declare the number of matrices
    int n;

    // Array to store matrix dimensions
    int p[20];

    // Input the number of matrices
    cout << "Enter number of matrices: ";
    cin >> n;

    // Input the dimensions of all matrices
    cout << "Enter dimensions of matrices: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    // Create DP table and initialize all values to 0
    int m[20][20] = {0};

    // len represents the length of the matrix chain
    for (int len = 2; len <= n; len++)
    {
        // Select the starting matrix
        for (int i = 1; i <= n - len + 1; i++)
        {
            // Calculate the ending matrix
            int j = i + len - 1;

            // Initialize minimum cost to infinity
            m[i][j] = INT_MAX;

            // Try every possible position to split the chain
            for (int k = i; k < j; k++)
            {
                // Calculate the cost of multiplying the two parts
                int cost = m[i][k] +
                           m[k + 1][j] +
                           p[i - 1] * p[k] * p[j];

                // Update the minimum multiplication cost
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                }
            }
        }
    }

    // Display the minimum number of scalar multiplications
    cout << "Minimum number of scalar multiplications: "
         << m[1][n] << endl;

    return 0;
}

// Matrix Chain Multiplication uses Dynamic Programming.
// It finds the best order to multiply a chain of matrices.
// Different multiplication orders can have different costs.
// The DP table stores the minimum multiplication cost.
// The objective is to minimize the number of scalar multiplications.
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
