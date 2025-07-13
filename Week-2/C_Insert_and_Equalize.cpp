#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a, ll b)
{
    return b == 0 ? abs(a) : gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }

        sort(a.begin(), a.end());

        ll g = 0;
        for (int i = 1; i < n; ++i)
        {
            g = gcd(g, a[i] - a[i - 1]);
        }

        ll totalops = 0;
        for (int i = 0; i < n; ++i)
        {
            totalops += (a[n - 1] - a[i]) / g;
        }

        ll mesisingops = 0;
        ll lastelement = a[n - 1];
        int arrptr = n - 2;

        while (arrptr >= 0 && a[arrptr] == lastelement - (n - 1 - arrptr) * g)
        {
            arrptr--;
        }

        mesisingops = n - 1 - arrptr;

        totalops += mesisingops;

        cout << totalops << "\n";
    }
    return 0;
}