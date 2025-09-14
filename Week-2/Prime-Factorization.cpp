#include <bits/stdc++.h>
using namespace std;

const int maxN = 30;
vector<int> allprimes;
void sieve()
{
    vector<bool> prime(maxN + 1, true);

    for (int i = 2; i * i <= maxN; i++)
    {
        if (prime[i])
        {
            for (int j = i + i; j <= maxN; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= maxN; i++)
    {
        if (prime[i])
        {
            allprimes.push_back(i);
        }
    }
}

int main()
{

    sieve();

    // for (auto x : allprimes)
    // {
    //     cout << x << endl;
    // }

    int n;
    cin >> n;

    map<int, int> cnt;

    int idx = 0;

    while (n > 1)
    {
        while (true)
        {
            if (n % allprimes[idx] != 0)
            {
                break;
            }

            cnt[allprimes[idx]]++;
            n /= allprimes[idx];
        }
        idx++;
    }

    for (auto [x, y] : cnt)
    {
        cout << x << " -> " << y << endl;
    }

    return 0;
}
