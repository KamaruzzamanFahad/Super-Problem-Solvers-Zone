#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int h, n;
        cin >> h >> n;
        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> a[i].second;
        }

        sort(a.begin(), a.end(), cmp);

        auto ok = [&](long long mid)
        {
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += (mid / a[i].second + 1) * a[i].first;
                if (sum >= h)
                {
                    return true;
                }
            }
            return sum >= h;
        };

        long long l = 0, r = 1e12, mid, ans = 0;

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
        cout << ans + 1 << endl;
    }

    return 0;
}
