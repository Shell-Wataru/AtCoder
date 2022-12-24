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
    ll L, X, Y, S, D;
    cin >> L >> X >> Y >> S >> D;
    cout << fixed << setprecision(12);
    if (S <= D)
    {
        if (Y > X)
        {
            cout << min(1.0 * (D - S) / (X + Y), 1.0 * (S - (D - L)) / (Y - X)) << endl;
        }
        else
        {
            cout << 1.0 * (D - S) / (X + Y) << endl;
        }
    }
    else
    {
        if (Y > X)
        {
            cout << min(1.0 * (D + L - S) / (X + Y), 1.0 * (S - D) / (Y - X)) << endl;
        }
        else
        {
            cout << 1.0 * (D + L - S) / (X + Y) << endl;
        }
    }
    return 0;
}
