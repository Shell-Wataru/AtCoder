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

bool can_put(ll X, ll Y, ll B, ll C)
{
    if (X <= 0 || Y <= 0)
    {
        return false;
    }
    ll x_b = (B + Y - 1) / Y;
    ll x_c = (C + Y - 1) / Y;
    ll y_b = (B + X - 1) / X;
    ll y_c = (C + X - 1) / X;
    return (x_b + x_c <= X) || (y_b + y_c <= Y);
}
int solve()
{

    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    if (can_put(X - (A + Y - 1) / Y, Y, B, C) ||
        can_put(X, Y - (A + X - 1) / X, B, C) ||
        can_put(X - (B + Y - 1) / Y, Y, C, A) ||
        can_put(X, Y - (B + X - 1) / X, C, A) ||
        can_put(X - (C + Y - 1) / Y, Y, A, B) ||
        can_put(X, Y - (C + X - 1) / X, A, B))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
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
    return 0;
}