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
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

void warshall_floyd(int n, vector<vector<ll>> &d)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    // 整数の入力
    ll H, W;
    cin >> H >> W;
    vector<string> map;
    for (int i = 0; i < H; i++)
    {
        string s;
        cin >> s;
        map.push_back(s);
    }

    vector<vector<ll>> D(H * W, vector<ll>(H * W, BASE_NUM));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (map[i][j] == '.')
            {
                D[W * i + j][W * i + j] = 0;
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (map[i][j] == '.')
            {
                if (i > 0)
                {
                    if (map[i - 1][j] == '.')
                    {
                        D[W * (i - 1) + j][W * i + j] = 1;
                    }
                }

                if (i < H - 1)
                {
                    if (map[i + 1][j] == '.')
                    {
                        D[W * (i + 1) + j][W * i + j] = 1;
                    }
                }

                if (j > 0)
                {
                    if (map[i][j - 1] == '.')
                    {
                        D[W * i + j - 1][W * i + j] = 1;
                    }
                }

                if (j < W - 1)
                {
                    if (map[i][j + 1] == '.')
                    {
                        D[W * i + j + 1][W * i + j] = 1;
                    }
                }
            }
        }
    }

    warshall_floyd(H * W, D);
    ll max_d = 0;
    for (int i = 0; i < H * W; i++)
    {
        for (int j = 0; j < H * W; j++)
        {
            if (D[i][j] < BASE_NUM)
            {
                max_d = max(max_d, D[i][j]);
            }
        }
    }
    cout << max_d << endl;
    return 0;
}