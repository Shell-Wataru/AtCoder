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
#include <set>
#include <stack>
#include <atcoder/mincostflow>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

ll distance(ll x, ll y)
{
    if ((x + y) % 2 == 0)
    {
        return max(abs(x), abs(y));
    }
    else if (x % 2 == 1)
    {
        return abs(x - 1) / 2 + abs(y) / 2;
    }
    else
    {

        return abs(x) / 2 + abs(y - 1) / 2;
    }
}
int solve()
{
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    cout << distance(ax, ay) <<","<< distance(bx, by) <<","<<  distance(cx, cy) << endl;
    cout << distance(ax, ay) + distance(bx, by) + distance(cx, cy) << endl;
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    cout << flush;
    return 0;
}
