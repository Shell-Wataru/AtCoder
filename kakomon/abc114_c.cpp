#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

ll my_pow(ll x, ll y)
{
    if (y == 0)
    {
        return 1LL;
    }
    else
    {
        ll y_2 = my_pow(x, y / 2);
        ll yy = y_2 * y_2;
        if (y % 2 == 0)
        {
            return yy;
        }
        else
        {
            return yy * x;
        }
    }
}

int nagomi(ll n, ll used_count)
{
    // cout << n << " " << used_count << endl;
    if (used_count == 0)
    {
        return my_pow(3, n) - 3 * my_pow(2, n) + 3 * my_pow(1, n);
    }
    else if (used_count == 1)
    {
        return my_pow(3, n) - 2 * my_pow(2, n) + my_pow(1, n);
    }
    else if (used_count == 2)
    {
        return my_pow(3, n) - my_pow(2, n);
    }
    else
    {
        //3
        return my_pow(3, n);
    }
}
int main()
{
    // 整数の入力
    string N;
    ll ans = 0;
    cin >> N;
    ll keta = N.size();
    bool can_max = true;

    vector<ll> candidates = {3, 5, 7};
    int use3 = 0;
    int use5 = 0;
    int use7 = 0;
    for (int i = 0; i < keta; i++)
    {
        ll n = N[i] - '0';
        if (can_max)
        {
            can_max = false;
            if (i != 0)
            {
                ans += nagomi(keta - i, 0);
            }
            for (auto c : candidates)
            {
                if (c == n)
                {
                    can_max = true;
                    if (c == 3)
                    {
                        use3 = 1;
                    }
                    else if (c == 5)
                    {
                        use5 = 1;
                    }
                    else if (c == 7)
                    {
                        use7 = 1;
                    }
                }
                else if (c < n)
                {
                    ans += nagomi(keta - 1 - i, (use3 | (c == 3)) + (use5 | (c == 5)) + (use7 | (c == 7)));
                }
            }
        }
        else
        {
            // cout << "!!!" << endl;
            ans += nagomi(keta - i, 0);
        }
    }
    if (can_max && use3 & use5 & use7){
        ans++;
    }
    cout << ans << endl;
    return 0;
}