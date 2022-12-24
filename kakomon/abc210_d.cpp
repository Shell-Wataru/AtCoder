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

int main()
{
    // 整数の入力
    ll H, W, C;
    cin >> H >> W >> C;
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<vector<ll>> DP_A(H + 1, vector<ll>(W + 1, numeric_limits<ll>::max() / 2));
    vector<vector<ll>> DP_B(H + 1, vector<ll>(W + 1, numeric_limits<ll>::max() / 2));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            DP_A[i + 1][j + 1] = min(min(DP_A[i + 1][j], DP_A[i][j + 1]), A[i][j] - C * (i + j));
            // cout << DP_A[i+1][j+1];
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = W - 1; j >= 0; j--)
        {
            DP_B[i + 1][j] = min(min(DP_B[i + 1][j + 1], DP_B[i][j]), A[i][j] - C * (i - j));
        }
    }
    // for (int i = 0; i <= H; i++)
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         cout << DP_A[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    ll ans = numeric_limits<ll>::max();
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            ans = min(ans, A[i][j] + C * (i + j) + min(DP_A[i + 1][j], DP_A[i][j + 1]));
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = W-1; j >= 0; j--)
        {
            ans = min(ans, A[i][j] + C * (i - j) + min(DP_B[i + 1][j+1], DP_B[i][j]));
        }
    }
    cout << ans << endl;
    return 0;
}