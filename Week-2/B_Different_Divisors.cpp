#include <bits/stdc++.h>
using namespace std;

const int mxN = 200000;
vector<int> allprimes;

void sieve()
{
    vector<bool> isPrime(mxN + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= mxN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= mxN; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= mxN; i++)
    {
        if (isPrime[i])
            allprimes.push_back(i);
    }
}

int main()
{
    sieve();

    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;

        int p1 = *lower_bound(allprimes.begin(), allprimes.end(), d + 1);
        int p2 = *lower_bound(allprimes.begin(), allprimes.end(), p1 + d);

        cout << 1LL * p1 * p2 << endl;
    }

    return 0;
}
