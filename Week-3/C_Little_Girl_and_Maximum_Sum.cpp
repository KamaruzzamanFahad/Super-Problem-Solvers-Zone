#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> d(n + 1);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        d[l]++;
        d[r + 1]--;
    }

    for (int i = 1; i < n; i++)
    {
        d[i] += d[i - 1];
    }

    sort(a.begin(), a.end());
    sort(d.begin(), d.end() - 1);
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += (long long)a[i] * d[i];
    }
    cout << ans << endl;
    return 0;
}
