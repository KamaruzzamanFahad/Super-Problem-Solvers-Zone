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
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> precnt(26, 0);
        vector<int> suffcnt(26, 0);

        precnt[s[0] - 'a']++;

        for (int i = 2; i < n; ++i)
        {
            suffcnt[s[i] - 'a']++;
        }

        bool found = false;
        for (int i = 1; i < n - 1; ++i)
        {
            if (precnt[s[i] - 'a'] > 0 || suffcnt[s[i] - 'a'] > 0)
            {
                found = true;
                break;
            }
            precnt[s[i] - 'a']++;

            if (i + 1 < n)
            {
                suffcnt[s[i + 1] - 'a']--;
            }
        }

        if (found)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}