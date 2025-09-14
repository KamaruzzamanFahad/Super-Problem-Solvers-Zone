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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        auto ok = [&](int mid)
        {
            int segment = 0;
            vector<int> count(mid, 0);
            int distance = 0;
            vector<int> temp;
            temp.reserve(mid);

            for (int val : a)
            {
                if (val < mid)
                {
                    if (count[val] == 0)
                    {
                        distance++;
                        temp.push_back(val);
                    }
                    count[val]++;
                }
                if (distance == mid)
                {
                    segment++;

                    distance = 0;
                    for (int idx : temp)
                    {
                        count[idx] = 0;
                    }
                    temp.clear();
                }
            }

            return segment >= k;
        };

        int ans = 0;
        int l = 1, r = n + 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
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