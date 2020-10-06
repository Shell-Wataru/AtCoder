#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n, m;
    cin >> n;
    vector<ll> a(n);
    ll max_a = 0;
    for (int i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        a[i] = b + max_a;
        max_a = max(max_a,a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
        solve();
    // }
    return 0;
}
