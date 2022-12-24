#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cmath>
using namespace std;
using ll = long long;

int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<pair<ll, ll>> engines(n);
    for (int i = 0; i < n; i++)
    {
        cin >> engines[i].first >> engines[i].second;
    }
    double answer = 0;
    for (int j = 0; j < n; j++)
    {
        bool changed = true;
        vector<bool> used(n, false);
        ll x = 0;
        ll y = 0;
        while (changed)
        {
            changed = false;
            for (int i = 0; i < n; i++)
            {
                ll new_x;
                ll new_y;
                if (used[(i+j)%n])
                {
                    new_x = x - engines[(i+j)%n].first;
                    new_y = y - engines[(i+j)%n].second;
                }
                else
                {
                    new_x = x + engines[(i+j)%n].first;
                    new_y = y + engines[(i+j)%n].second;
                }
                if (x * x + y * y < new_x * new_x + new_y * new_y)
                {
                    x = new_x;
                    y = new_y;
                    used[(i+j)%n] = !used[(i+j)%n];
                    changed = true;
                }
            }
        }
        answer = max(answer,hypot(x, y));
    }
    cout << fixed << setprecision(12) << answer << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
