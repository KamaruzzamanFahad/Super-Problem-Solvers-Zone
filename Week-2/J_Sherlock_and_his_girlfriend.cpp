#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n <= 2)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << 1 << (i == n - 1 ? "" : " ");
        }
        cout << endl;
        return 0;
    }

    cout << 2 << endl;

    int limit = n + 1;
    vector<bool> isprime(limit + 1, true);
    isprime[0] = isprime[1] = false;

    for (int p = 2; p * p <= limit; ++p)
    {
        if (isprime[p])
        {
            for (int i = p * p; i <= limit; i += p)
                isprime[i] = false;
        }
    }

    for (int i = 2; i <= limit; ++i)
    {
        cout << (isprime[i] ? 1 : 2) << (i == limit ? "" : " ");
    }
    cout << endl;

    return 0;
}