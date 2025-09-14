#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> cnts(100001, 0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int s;
        cin >> s;

        int temp = s;
        for (int d = 2; d * d <= temp; ++d)
        {
            if (temp % d == 0)
            {
                cnts[d]++;
                while (temp % d == 0)
                {
                    temp /= d;
                }
            }
        }
        if (temp > 1)
        {
            cnts[temp]++;
        }
    }

    int mxpokemon = 1;
    for (int count : cnts)
    {
        if (count > mxpokemon)
        {
            mxpokemon = count;
        }
    }

    cout << mxpokemon << endl;
    return 0;
}