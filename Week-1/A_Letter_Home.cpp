#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> x(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        int mn = *min_element(x.begin(), x.end());
        int mx = *max_element(x.begin(), x.end());

        int step = min(abs(s - mn), abs(s - mx)) + (mx - mn);
        cout << step << '\n';
    }
    return 0;
}
