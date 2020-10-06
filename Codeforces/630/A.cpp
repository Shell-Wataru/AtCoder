#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator> // std::rbegin, std::rend

using namespace std;
using ll = long long;

bool is_clear(ll a, ll b, ll x1, ll x2)
{
    if (a == 0 && b == 0){
        return true;
    }else if (a == b)
    {
        if (x1 == 0 && x2 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if (a < b)
    {
        if (b - a <= x2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (a - b <= x1){
            return true;
        }else{
            return false;
        }
    }
}
int solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if (is_clear(a,b,abs(x - x1),abs(x2 -x)) && is_clear(c,d,abs(y - y1),abs(y2 -y))){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}