#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l = 1, r = 2e9, mid, ans = 0;

    auto ok = [&](int mid)
    {
        long long cnt = 0;
        for (int i = (n/2); i < n; i++)
        {
            cnt += (mid > a[i] ? (mid - a[i]) : 0);
        }
        return cnt <= k;
    };

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

    return 0;
}
