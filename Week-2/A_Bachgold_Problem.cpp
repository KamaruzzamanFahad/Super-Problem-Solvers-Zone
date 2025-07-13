#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt;

    if (n % 2 == 0)
    {
        cnt = n / 2;
        cout << cnt << endl;
        for (int i = 0; i < cnt; i++)
        {
            cout << 2 << " ";
        }
    }
    else
    {
        cnt = (n - 3) / 2;
        cout << cnt + 1 << endl;
        for (int i = 0; i < cnt; i++)
        {
            cout << 2 << " ";
        }
        cout << 3;
    }

    cout << endl;
    return 0;
}
