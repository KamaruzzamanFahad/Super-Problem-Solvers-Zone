#include <bits/stdc++.h>
using namespace std;

bool check(long long x, int n, int m, const vector<vector<int>> &a)
{
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] > x)
            {
                p.push_back({i, j});
            }
        }
    }

    if (p.empty())
    {
        return true;
    }

    for (const auto &cell : p)
    {
        if (a[cell.first][cell.second] > x + 1)
        {
            return false;
        }
    }

    int r0 = p[0].first;
    int c0 = p[0].second;

    bool possible1 = true;
    int col_to_cover = -1;
    for (const auto &cell : p)
    {
        if (cell.first != r0)
        {
            if (col_to_cover == -1)
            {
                col_to_cover = cell.second;
            }
            else if (col_to_cover != cell.second)
            {
                possible1 = false;
                break;
            }
        }
    }
    if (possible1)
    {
        return true;
    }

    bool possible2 = true;
    int row_to_cover = -1;
    for (const auto &cell : p)
    {
        if (cell.second != c0)
        {
            if (row_to_cover == -1)
            {
                row_to_cover = cell.first;
            }
            else if (row_to_cover != cell.first)
            {
                possible2 = false;
                break;
            }
        }
    }
    if (possible2)
    {
        return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        int max_val = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] > max_val)
                {
                    max_val = a[i][j];
                }
            }
        }

        long long low = 0, high = max_val, ans = max_val;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (check(mid, n, m, a))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}