#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> feq(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            if (a <= n)
            {
                feq[a]++;
            }
        }

        vector<int> counts(n + 1, 0);
        for (int h = 1; h <= n; ++h)
        {
            if (feq[h] > 0)
            {
                for (int j = h; j <= n; j += h)
                {
                    counts[j] += feq[h];
                }
            }
        }

        int mxfrogs = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (counts[i] > mxfrogs)
            {
                mxfrogs = counts[i];
            }
        }

        cout << mxfrogs << endl;
    }

    return 0;
}