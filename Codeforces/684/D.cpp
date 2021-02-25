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
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    cin >> n;
    vector<ll> a(40, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ll temp = a[(2 * i) % n] ^ a[(2 * i + 1) % n] ^ a[(2 * i  + 2) % n];
        a[(2 * i) % n] = temp;
        a[(2 * i + 1) % n] = temp;
        a[(2 * i + 2) % n] = temp;
    }
    bool all_same = true;
    // cout << a[0] << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
        if (a[i] != a[0])
        {

            all_same = false;
        }
    }
    if (all_same)
    {
        cout << "YES"
             << "\n";
        cout << n << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << (2 * i ) % n + 1 << " " << (2 * i + 1) % n + 1 << " " << (2 * i + 2) % n + 1 << "\n";
        }
        cout << flush;
    }
    else
    {
        cout << "NO\n";
        cout << flush;
    }
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
