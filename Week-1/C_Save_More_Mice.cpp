#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(k);

        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }

        sort(a.rbegin(), a.rend());

        // auto ok = [&](long long mid)
        // {
        //     long long cnt = 0;
        //     int mic = 0;

        //     for (int i=0; i<k; i++)
        //     {

        //         if ((n - a[i]) + cnt <= n)
        //         {
        //             cnt += n - a[i];
        //             mic++;
        //         }
        //     }

        //     return mic >= mid;
        // };

        auto ok = [&](long long mid)
        {
            long long cnt = 0;

            for (int i = 0; i < mid; i++)
            {
                if (i >= k)
                    return false;
                if (cnt >= a[i])
                    return false;
                cnt += (n - a[i]);
            }

            return true;
        };

        long long l = 0, r = n, mid, ans = 0;

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
