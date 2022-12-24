#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <cmath>
#include <set>
#include <numeric>
#include <climits>
#include <unordered_map>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll sx, sy, tx, ty, T, V;
    cin >> sx >> sy >> tx >> ty >> T >> V;
    ll N;
    cin >> N;
    bool can = false;
    for (int i = 0; i < N; i++)
    {
        ll x, y;
        cin >> x >> y;
        double d = hypot(sx - x, sy - y) + hypot(tx - x, ty - y) <= T * v;
        double eps = 1e-8;
        if (d <= T * V + eps)
        {
            can = true;
        }
    }
    if (can)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
