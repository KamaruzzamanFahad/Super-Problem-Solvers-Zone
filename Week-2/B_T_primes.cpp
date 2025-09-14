#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{
    if (n == 1) return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool isPerfectSqrt(long long n)
{
    long long x = sqrtl(n);
    return (x * x) == n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;

        if (isPerfectSqrt(x) && isPrime(sqrtl(x)))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}
