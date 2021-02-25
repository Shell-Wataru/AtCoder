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
    scanf("%lld", &n);
    ll l;
    ll r;
    ll all_second_index;
    ll front_second_index;

    cout << "? " << 1 << " " << n << endl;
    cin >> all_second_index;
    if (all_second_index == 1){
        front_second_index = -1;
    }else{
        cout << "? " << 1 << " " << all_second_index << endl;
        cin >> front_second_index;
    }
    if (all_second_index == front_second_index)
    {
        l = 1;
        r = all_second_index;
        while (l + 1 != r)
        {
            ll center = (l + r) / 2;
            cout << "? " << center << " " << all_second_index << endl;
            ll index;
            cin >> index;
            if (index == all_second_index)
            {
                l = center;
            }
            else
            {
                r = center;
            }
        }
        cout << "! " << l << endl;
    }
    else
    {
        l = all_second_index;
        r = n;
        while (l + 1 != r)
        {
            ll center = (l + r) / 2;
            cout << "? " << all_second_index << " " << center << endl;
            ll index;
            cin >> index;
            if (index == all_second_index)
            {
                r = center;
            }
            else
            {
                l = center;
            }
        }
        cout << "! " << r << endl;
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
