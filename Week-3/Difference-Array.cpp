#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n+1); 
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> d(n + 2), pref(n + 2);

    for (int i = 1; i <= q; i++)
    {
        int x, l, r;
        cin >> l >> r >> x;
        d[l] += x;
        d[r + 1] -= x;
    }

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + d[i];
    }

    for (int i = 1; i < n; i++)
    {
        cout << a[i] + pref[i] << " ";
    }
    cout << endl;

    return 0;
}
