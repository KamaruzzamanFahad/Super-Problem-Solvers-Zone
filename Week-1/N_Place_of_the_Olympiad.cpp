#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        auto ok = [&](long long mid)
        {
            long long student = (m / (mid + 1)) * mid + (m % (mid + 1));
            long long totalstudent = student * n;
            return totalstudent >= k;
        };

        long long l = 1, r = k, mid, ans = 0;

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (ok(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
