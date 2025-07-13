#include <bits/stdc++.h>

using namespace std;

const int mxN = 10000007;
long long ans[mxN];
int dp[mxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < mxN; ++i)
    {
        if (dp[i] == 0)
        {
            for (long long j = i; j < mxN; j += i)
            {
                dp[j]++;
            }
        }
    }

    ans[0] = 0;
    ans[1] = 0;

    for (int i = 2; i < mxN; ++i)
    {
        ans[i] = ans[i - 1] + dp[i];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }

    return 0;
}