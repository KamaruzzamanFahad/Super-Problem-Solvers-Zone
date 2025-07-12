#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> allprimes;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            allprimes.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
    {
        allprimes.push_back(n);
    }

    for (auto x : allprimes)
    {
        cout << x << endl;
    }
    return 0;
}
