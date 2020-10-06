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
namespace mp = boost::multiprecision;

using namespace std;
using ll = long long;

int main()
{
    ll X, Y, N;
    cin >> X >> Y >> N;
    vector<vector<ll>> DP(X + Y + 1, vector<ll>(X + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        ll t, h;
        cin >> t >> h;
        for (int x = X + Y; x >= 0; x--)
        {
            for (int y = X; y >= 1; y--)
            {
                if (x - t >= 0)
                {
                    DP[x][y] = max(DP[x][y], DP[x - t][y - 1] + h);
                }
            }
        }
    }
    ll max_h = 0;
    for (int x = 0; x <= X + Y; x++)
    {
        for (int y = 0; y <= X; y++)
        {
            max_h = max(max_h, DP[x][y]);
        }
    }
    cout << max_h << endl;
    return 0;
}