#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    auto ok = [&](ll mid)
    {
        ll cnt = 0, sum = 0;
        for (ll i = 0; i < n; i++)
        {
            sum += min((ll)a[i], mid);
            if (sum >= mid)
            {
                cnt++;
                sum %= mid;
            }
        }
        return cnt >= k;
    };

    ll l = 0, r = 1e14, mid, ans = 0;

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
