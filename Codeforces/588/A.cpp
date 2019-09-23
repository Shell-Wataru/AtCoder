#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    vector<ll> A;
    ll a, total;
    total = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> a;
        total += a;
        A.push_back(a);
    }

    for (int i = 0; i < 4; i++)
    {
        if (A[i] == total - A[i])
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (total == (A[i] + A[j]) * 2)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}
