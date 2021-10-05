#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n, U, R, D, L;
    cin >> n >> U >> R >> D >> L;
    vector<ll> candidates = {1,0};
    bool can_make = false;
    for (auto ul : candidates)
    {
        for (auto ur : candidates)
        {
            for (auto dl : candidates)
            {
                for (auto dr : candidates)
                {
                    // cout << ul << "," << ur << "," << dl << "," << dr << endl;
                    if (!(ul + ur <= U && U <= n - 2 + ul + ur)){
                        continue;
                    }
                    if (!(dl + dr <= D && D <= n - 2 + dl + dr)){
                        continue;
                    }

                    if (!(ul + dl <= L && L <= n - 2 + ul + dl)){
                        continue;
                    }
                    if (!(ur + dr <= R && R <= n - 2 + ur + dr)){
                        continue;
                    }
                    can_make = true;
                }
            }
        }
    }
    if (can_make)
    {
        cout << "YES"
             << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }

    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
