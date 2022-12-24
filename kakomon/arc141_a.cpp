#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    ll ans = 0;
    for (int i = 2; i <= 18; i++)
    {

        for (int j = 1; i * j <= 18; j++)
        {

            ll basebase = 1;
            for (int l = 0; l < j - 1; l++)
            {
                basebase *= 10;
            }
            // cout << "base" << endl;
            // cout << basebase << endl;
            ll base = 0;
            for (int k = 0; k < i; k++)
            {
                base *= basebase;
                base *= 10;
                base += 1;
            }
            // cout << basebase * 10 << endl;
            ans = max(ans, min(N / base, basebase * 10 - 1) * base);
        }
    }
    cout << ans << endl;
    return 0;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
