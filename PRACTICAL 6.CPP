
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    int p[20];

    cout << "Enter number of matrices: ";
    cin >> n;

    cout << "Enter dimensions of matrices: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    int m[20][20] = {0};

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] +
                           m[k + 1][j] +
                           p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                }
            }
        }
    }

    cout << "Minimum number of scalar multiplications: "
         << m[1][n] << endl;

    return 0;
}
