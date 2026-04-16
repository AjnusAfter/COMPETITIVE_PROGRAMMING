#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'sumXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long sumXor(long n) {
    if (n == 0)
    {
        return 1;
    }

    long zero_bits = 0;

    while (n > 0)
    {
        if ((n & 1) == 0)
        {
            zero_bits++;
        }

        n = n >> 1;
    }

    return 1L << zero_bits;
}

int main()
{
    long n;
    cin >> n;

    cout << sumXor(n) << "\n";

    return 0;
}
