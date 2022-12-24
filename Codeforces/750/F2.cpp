#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{

    ll n;
    scanf("%lld", &n);
    vector<ll> can_make(1ll << 13, numeric_limits<ll>::max());
    vector<ll> a(n);
    vector<vector<ll>> a_indexes(1ll << 13);
    can_make[0] = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        a_indexes[a[i]].push_back(i);
    }
    for (int i = 0; i < 1ll << 13; i++)
    {
        for (int j = 0; j < 1ll << 13; j++)
        {
            if (can_make[j] == numeric_limits<ll>::max())
            {
                continue;
            }
            for (auto index : a_indexes[i])
            {

                if (can_make[j ^ i] < index)
                {
                    break;
                }
                else if (can_make[j] < index)
                {
                    can_make[j ^ i] = min(can_make[j ^ i], index);
                    break;
                }
            }
        }
    }
    vector<ll> answers;
    for (int j = 0; j < 1ll << 10; j++)
    {
        if (can_make[j] < numeric_limits<ll>::max())
        {
            answers.push_back(j);
        }
    }
    cout << answers.size() << "\n";
    for (auto a : answers)
    {
        cout << a << " ";
    }
    cout << "\n";
    return 0;
}
int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}