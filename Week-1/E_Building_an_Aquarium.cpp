#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        auto ok = [&](long long h)
        {
            long long cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] < h)
                {
                    cnt += (h - a[i]);
                }

                if (cnt > x)
                {
                    return false;
                }
            }
            return cnt <= x;
        };

        long long l = 0, r = 1e18, mid, ans = 0;

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (ok(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
