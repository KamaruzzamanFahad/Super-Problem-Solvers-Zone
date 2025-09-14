#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> k(n);

    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }

    ll l = 1, r = 1e18, mid, ans = 0;

    auto ok = [&](ll seconds)
    {
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += (seconds / k[i]);

            if (cnt >= t)
            {
                return true;
            }
        }

        return false;
    };

    while (l <= r)
    {
        mid = (l + r) / 2;

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

    return 0;
}
