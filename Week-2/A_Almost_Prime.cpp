#include <bits/stdc++.h>
using namespace std;

const int maxN = 3000;
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

bool isAlmostPrime(int n)
{
    int cnt = 0;
    int idx = 0;

    while (n > 1 && idx < allprimes.size())
    {
        if (n % allprimes[idx] == 0)
        {
            cnt++;
            while (n % allprimes[idx] == 0)
            {
                n /= allprimes[idx];
            }
        }
        idx++;
    }

    return cnt == 2;
}

int main()
{
    sieve();

    int n;
    cin >> n;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (isAlmostPrime(i))
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
